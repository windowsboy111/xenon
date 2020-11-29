let url_input = document.getElementById("url");
// let tabctl = document.getElementById("tabctl");
// let navctl = document.getElementById("navctl");
let ctxpage = document.getElementById("xenon-ctx");

async function corResize (_event) {
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
ctxpage.addEventListener("click", async _event => {
    setTimeout(() => {
        url_input.value = ctxpage.getAttribute('src');
    }, 0.1);
});
document.addEventListener("resize", corResize);


// tabs
class TabCtl {
    tabctlEle = document.getElementById("tabctl");
    curPos = 0;
    tabs = [];
    tabsEle = [];
    constructor () {
        this.newTab();
    }
    newTab() {
        let tab = new Tab;
        this.tabs.push(tab);
        this.loadTab(this.tabs.length-1);
        this.tabctlEle.appendChild(document.createElement("button").appendChild(document.createTextNode("Home")));
    }
    rmTab(pos) {
        this.tabctlEle.removeChild(this.tabsEle[pos]);
        this.tabs.splice(pos, 1);
        this.tabsEle.splice(pos, 1);
        if (this.curPos >= this.tabs.length) --this.curPos;  // if there's no tab on RHS then load the left one
        this.loadTab(this.curPos); 
    }
    loadTab(pos) {
        this.tabs[this.curPos].url();  // store the url for the old tab
        this.curPos = pos;
        this.tabs[pos].load();  // load the new tab
    }
}

class Tab {
    constructor (pos, url, title) {
        this.pos = pos;
        this.url = url;
        this.title = title;
    }
    /**
     * load the url attrib in `this` into the src
     */
    load() {
        ctxpage.setAttribute("src", this.url);
        url_input.value = this.url;
    }
    /**
     * @returns url of the tab
     */
    get url() {
        this.url = ctxpage.getAttribute("src");
        return this.url;
    }
    /**
     * @param url {string}
     */
    set url(url) {
        this.url = url;
        this.load();
    }
}


async function main () {
    corResize(null);
    let tabCtl = new TabCtl();
    tabCtl.loadTab(0);
}
