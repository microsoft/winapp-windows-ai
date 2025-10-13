const windowsaiAddon = require('./windows-ai-addon/build/Release/windows-ai-addon.node');

windowsaiAddon.version = require('./package.json').version;

module.exports = windowsaiAddon;