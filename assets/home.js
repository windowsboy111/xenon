const fs = require('fs');
let url_input = document.getElementById("url");
// let tabctl = document.getElementById("tabctl");
// let navctl = document.getElementById("navctl");
let ctxpage = document.getElementById("xenon-ctx");
let newTab = document.getElementById("newTab");
let rmTab = document.getElementById("rmTab")

async function corResize(_event) {
    let height = Number(document.body.style.height);
    let up_l = Number(url_input.style.width) + Number(url_input.style.top);
    ctxpage.setAttribute("style", `position: absolute; height: ${height - up_l}px; min-width: 100%; left: 0px; bottom: 0px; border: none;`);
}

url_input.addEventListener("keyup", async event => {
    if (event.key === "Enter") {
        let url = url_input.value;
        console.debug(`req ${url}`);
        ctxpage.setAttribute("src", url);
    }
});
document.addEventListener("resize", corResize);


// tabs
class TabCtl {
    tabctlEle = document.getElementById("tabctl");
    curPos = 0;
    tabs = [];
    tabsEle = [];
    constructor() {
        this.newTab();
    }
    newTab() {
        let but = document.createElement("button");
        let tab = new Tab(this.tabs.length - 1, "", "", but);
        this.tabs.push(tab);
        this.loadTab(this.tabs.length - 1);
        this.curPos = this.tabs.length - 1
        but.setAttribute("onclick", `tabCtl.loadTab(${this.curPos})`);
        but.appendChild(document.createTextNode(`Tab ${this.tabs.length}`));
        this.tabctlEle.appendChild(but);
        this.tabsEle.push(but)
    }
    rmTab() {
        let pos = this.curPos;
        let but = this.tabctlEle.removeChild(this.tabctlEle.childNodes[pos]);
        this.tabs.splice(pos, 1);
        this.tabsEle.splice(pos, 1);
        if (this.tabs.length == 0) return this.newTab();
        this.loadTab((this.curPos >= this.tabs.length) ? (--this.curPos) : this.curPos);
    }
    loadTab(pos) {
        if (pos != this.curPos) {
            this.tabs[this.curPos].link = ctxpage.getAttribute('src');  // store the url for the old tab
            this.tabs[this.curPos].unload();
            this.curPos = pos;
        }
        this.tabs[pos].load();  // load the new tab
    }
}

class Tab {
    constructor(pos, url = "", title = "", but) {
        this.pos = pos;
        this.link = url;
        this.title = title;
        this.but = but
        this.load();
    }
    /**
     * load the url attrib in `this` into the src
     */
    load() {
        ctxpage.setAttribute("src", this.link);
        url_input.value = "";
        if (this.link != "null") {
            url_input.value = this.link;
        }
        this.but.setAttribute("class", "but-activated")
    }
    unload() {
        this.but.setAttribute("class", "");
    }
    /**
     * @returns url of the tab
     */
    get url() {
        this.link = ctxpage.getAttribute("src");
        return this.link;
    }
    /**
     * @param url {string}
     */
    set url(url) {
        this.link = url;
        this.load();
    }
}


// main
corResize(null);
let tabCtl = new TabCtl();
tabCtl.loadTab(0);
url_input.value = "";