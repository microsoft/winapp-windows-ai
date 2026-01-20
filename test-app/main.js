const { app, BrowserWindow } = require('electron/main');
const {
  LanguageModel,
  AIFeatureReadyResultState,
  TextSummarizer,
  LanguageModelResponseStatus,
} = require("../index.js");


const createWindow = () => {
  const win = new BrowserWindow({
    width: 800,
    height: 600,
    autoHideMenuBar: true,
    webPreferences: {
      preload: __dirname + '/preload.js',
      sandbox: false,
    }
  })

  win.loadFile('index.html')
}

app.whenReady().then(() => {
  createWindow()

  app.on('activate', () => {
    if (BrowserWindow.getAllWindows().length === 0) {
      createWindow()
    }
  })
})

app.on('window-all-closed', () => {
  if (process.platform !== 'darwin') {
    app.quit()
  }
})