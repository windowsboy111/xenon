const electron = require('electron');

const app = electron.app;

async function createWin() {
    var win = new electron.BrowserWindow({
        width: 800,
        height: 600,
        webPreferences: {
            nodeIntegration: true
        }
    });

    win.loadFile('assets/home.html');
}

app.whenReady().then(createWin);


// listeners
app.on('window-all-closed', async () => {
    if (process.platform !== 'darwin') {
        app.quit();
    }
});

app.on('activate', async () => {
    if (BrowserWindow.getAllWindows().length === 0) {
        createWin();
    }
});
