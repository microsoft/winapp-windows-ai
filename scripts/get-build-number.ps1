<#
.SYNOPSIS
    Calculates the prerelease number based on the highest existing prerelease for the current version.

.DESCRIPTION
    This script finds the highest prerelease number for the current base version from git tags,
    then increments it by 1. If no prerelease exists for the current version, starts at 1.

.PARAMETER VersionFile
    Path to the package.json file. Defaults to ../package.json relative to this script.

.OUTPUTS
    Returns the prerelease number as an integer.

.EXAMPLE
    .\get-build-number.ps1
    # For version 0.1.3 with existing tags 0.1.3-prerelease.5, 0.1.3-prerelease.7
    # Returns: 8 (highest + 1)
#>

param(
    [string]$VersionFile = "$PSScriptRoot\..\package.json"
)

# Ensure we're in a git repository
if (-not (Test-Path .git)) {
    Write-Error "Not in a git repository root. Please run from repository root or ensure .git exists."
    exit 1
}

# Ensure package.json exists
if (-not (Test-Path $VersionFile)) {
    Write-Error "package.json not found at: $VersionFile"
    exit 1
}

try {
    # Read the current base version from package.json
    $packageJson = Get-Content $VersionFile | ConvertFrom-Json
    $baseVersion = $packageJson.version
    
    Write-Host "[PRERELEASE] Base version from package.json: $baseVersion" -ForegroundColor Cyan
    
    # Get all git tags that match the current base version with prerelease pattern
    $tagPattern = "$baseVersion-prerelease.*"
    $allTags = git tag -l 2>$null
    
    if ([string]::IsNullOrEmpty($allTags)) {
        Write-Host "[PRERELEASE] No git tags found, starting at prerelease.1" -ForegroundColor Yellow
        Write-Output "1"
        exit 0
    }
    
    # Filter tags that match our version pattern and extract prerelease numbers
    $matchingTags = $allTags | Where-Object { $_ -like $tagPattern }
    $prereleaseNumbers = @()
    
    foreach ($tag in $matchingTags) {
        if ($tag -match "$baseVersion-prerelease\.(\d+)") {
            $prereleaseNumbers += [int]$matches[1]
            Write-Host "[PRERELEASE] Found existing tag: $tag (prerelease.$($matches[1]))" -ForegroundColor Gray
        }
    }
    
    if ($prereleaseNumbers.Count -eq 0) {
        Write-Host "[PRERELEASE] No prerelease tags found for version $baseVersion, starting at prerelease.1" -ForegroundColor Yellow
        Write-Output "1"
    } else {
        $highestPrerelease = ($prereleaseNumbers | Measure-Object -Maximum).Maximum
        $nextPrerelease = $highestPrerelease + 1
        Write-Host "[PRERELEASE] Highest existing prerelease: $highestPrerelease, next: $nextPrerelease" -ForegroundColor Green
        Write-Output $nextPrerelease
    }
    
} catch {
    Write-Error "Failed to calculate prerelease number: $_"
    exit 1
}