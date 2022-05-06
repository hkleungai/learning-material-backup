function nav_btn_onclick() {
    switch (document.getElementsByTagName("nav")[0].style.display) {
        default:
        case 'none':
            document.getElementsByTagName("nav")[0].style.display = 'block';
            // document.getElementsByClassName('nav-button')[0].style.backgroundColor = '#FFF5F1';
            // document.getElementsByClassName('nav-button')[0].style.color = 'black';
            break;
        case 'block':
            document.getElementsByTagName("nav")[0].style.display = 'none';
            // document.getElementsByClassName('nav-button')[0].style.backgroundColor = '#205AA7';
            // document.getElementsByClassName('nav-button')[0].style.color = 'white';
            break;
    }
}

function body_onresize() {
    if (window.innerWidth >= 1024) {
        document.getElementsByTagName("nav")[0].style.display = 'block';
        // document.getElementsByClassName('nav-button')[0].style.backgroundColor = '#FFF5F1';
        // document.getElementsByClassName('nav-button')[0].style.color = 'black';
    } else {
        document.getElementsByTagName("nav")[0].style.display = 'none';
        // document.getElementsByClassName('nav-button')[0].style.backgroundColor = '#205AA7';
        // document.getElementsByClassName('nav-button')[0].style.color = 'white';
    }
}

function body_onload() {
    let url = document.URL;
    if (url.indexOf('?') != -1) {
        let id = url.split('?')[1];
        nav_link_onclick(id);
    }
    else
        nav_link_onclick('');

}

function nav_link_onclick(id) {

    if (window.innerWidth < 1024)
        document.getElementsByTagName("nav")[0].style.display = 'none';
    // document.getElementsByClassName('nav-button')[0].style.backgroundColor = '#205AA7';
    // document.getElementsByClassName('nav-button')[0].style.color = 'white';
    Array.from(document.getElementsByTagName('section')).forEach((item) => {
        item.style.display = 'none';
    });

    if (id == 'home' || id == '') {
        document.getElementById('announcements').style.display = 'block';
        document.getElementById('course_information').style.display = 'block';
    } else {
        item = document.getElementById(id);
        item.style.display = 'block';
    }
}
