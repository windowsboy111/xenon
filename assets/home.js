let url_input = document.getElementById("url");
let tabctl = document.getElementById("tabctl");
let navctl = document.getElementById("navctl");
let ctxpage = document.getElementById("xenon-ctx");

async function corResize (_event) {
    let height = Number(document.body.style.height);
    let up_l = Number(url_input.style.width) + Number(url_input.style.top);
    ctxpage.setAttribute("style", `position: absolute; height: ${height - up_l}px; min-width: 100%; left: 0px; bottom: 0px; border: none;`); 
}
corResize(null);

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


// @ts-ignore
// neel.callProc("postLoad");
