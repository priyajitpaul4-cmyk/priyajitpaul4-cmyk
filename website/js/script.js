/* ==========================================================================
   Code with C — interactions
   render lists · accordion · theme · nav · view-all toggles · reveal
   ========================================================================== */

(function () {
  "use strict";

  const $ = (sel, root) => (root || document).querySelector(sel);
  const $$ = (sel, root) => Array.from((root || document).querySelectorAll(sel));

  const ICONS = {
    play: '<svg viewBox="0 0 24 24" fill="currentColor" stroke="none"><path d="M8 5.5v13l11-6.5z"/></svg>',
    like: '<svg viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round"><path d="M7 10v12"/><path d="M15 5.88 14 10h5.83a2 2 0 0 1 1.92 2.56l-2.33 8A2 2 0 0 1 17.5 22H4a2 2 0 0 1-2-2v-8a2 2 0 0 1 2-2h2.76a2 2 0 0 0 1.79-1.11L12 2a3.13 3.13 0 0 1 3 3.88z"/></svg>',
    comment: '<svg viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round"><path d="M21 11.5a8.38 8.38 0 0 1-.9 3.8 8.5 8.5 0 0 1-7.6 4.7 8.38 8.38 0 0 1-3.8-.9L3 21l1.9-5.7a8.38 8.38 0 0 1-.9-3.8 8.5 8.5 0 0 1 4.7-7.6 8.38 8.38 0 0 1 3.8-.9h.5a8.48 8.48 0 0 1 8 8z"/></svg>',
    chev: '<svg class="qa-chev" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round"><path d="M6 9l6 6 6-6"/></svg>',
  };

  /* ---------------------------------------------------------- programs */
  function renderPrograms() {
    const track = $("#programTrack");
    track.innerHTML = PROGRAMS.map(function (p) {
      const color = C_COLORS[p.c] || C_COLORS.purple;
      return (
        '<article class="program-card" style="--pc:' + color + '">' +
          '<span class="p-num">' + String(p.n).padStart(2, "0") + "</span>" +
          '<h3 class="p-title">' + p.title + "</h3>" +
          '<div class="p-foot">' +
            '<span class="p-cat">' + p.cat + "</span>" +
            '<button class="p-play" aria-label="Run program ' + p.n + '">' + ICONS.play + "</button>" +
          "</div>" +
        "</article>"
      );
    }).join("");
  }

  /* ---------------------------------------------------------- problems */
  function renderProblems() {
    const grid = $("#problemGrid");
    grid.innerHTML = PROBLEMS.map(function (p, i) {
      const label = p.diff.charAt(0).toUpperCase() + p.diff.slice(1);
      return (
        '<article class="problem-card">' +
          '<div class="pr-head"><strong>' + p.title + '</strong>' +
            '<span class="diff ' + p.diff + '">' + label + "</span></div>" +
          '<p class="pr-desc">' + p.desc + "</p>" +
          '<div class="pr-foot">' +
            '<span class="by">By ' + p.by + "</span>" +
            '<button class="pr-stat like" data-i="' + i + '" aria-label="Like problem">' +
              ICONS.like + "<span>" + p.likes + "</span></button>" +
            '<span class="pr-stat">' + ICONS.comment + "<span>" + p.comments + "</span></span>" +
          "</div>" +
        "</article>"
      );
    }).join("");

    grid.addEventListener("click", function (e) {
      const btn = e.target.closest("button.like");
      if (!btn) return;
      const i = Number(btn.dataset.i);
      const span = btn.querySelector("span");
      const liked = btn.classList.toggle("liked");
      PROBLEMS[i].liked = liked;
      span.textContent = PROBLEMS[i].likes + (liked ? 1 : 0);
    });
  }

  /* --------------------------------------------------------- interview */
  const QA_VISIBLE = 6;
  let qaExpanded = false;

  function renderQuestions() {
    const grid = $("#qaGrid");
    const list = qaExpanded ? QUESTIONS : QUESTIONS.slice(0, QA_VISIBLE);
    grid.dataset.rows = String(Math.ceil(list.length / 2));
    grid.innerHTML = list.map(function (item, i) {
      return (
        '<div class="qa-item">' +
          '<button class="qa-head" aria-expanded="false">' +
            '<span class="qa-num">' + String(i + 1).padStart(2, "0") + "</span>" +
            '<span class="qa-q">' + item.q + "</span>" + ICONS.chev +
          "</button>" +
          '<div class="qa-body"><p>' + item.a + "</p></div>" +
        "</div>"
      );
    }).join("");
  }

  function bindAccordion() {
    $("#qaGrid").addEventListener("click", function (e) {
      const head = e.target.closest(".qa-head");
      if (!head) return;
      const item = head.parentElement;
      const body = item.querySelector(".qa-body");
      const open = item.classList.toggle("open");
      head.setAttribute("aria-expanded", String(open));
      body.style.maxHeight = open ? body.scrollHeight + "px" : "0px";
    });

    $("#viewAllQBtn").addEventListener("click", function () {
      qaExpanded = !qaExpanded;
      renderQuestions();
      $("#viewAllQLabel").textContent = qaExpanded ? "Show Less" : "View All Questions";
    });
  }

  /* ---------------------------------------------------- view all toggle */
  function bindViewAll() {
    const btn = $("#viewAllBtn");
    const track = $("#programTrack");
    btn.addEventListener("click", function () {
      const on = track.classList.toggle("grid-mode");
      $("#viewAllLabel").textContent = on ? "Collapse to Row" : "View All 32 Programs";
      if (on) track.scrollIntoView({ behavior: "smooth", block: "nearest" });
    });
  }

  /* ------------------------------------------------------------- theme */
  function bindTheme() {
    const root = document.documentElement;
    let saved = null;
    try { saved = localStorage.getItem("cwc-theme"); } catch (err) { /* private mode */ }
    if (saved === "light" || saved === "dark") root.setAttribute("data-theme", saved);

    $("#themeToggle").addEventListener("click", function () {
      const next = root.getAttribute("data-theme") === "dark" ? "light" : "dark";
      root.setAttribute("data-theme", next);
      try { localStorage.setItem("cwc-theme", next); } catch (err) { /* ignore */ }
    });
  }

  /* -------------------------------------------------------------- nav */
  function bindNav() {
    const nav = $("#mainNav");
    const links = $$("a", nav);

    $("#navToggle").addEventListener("click", function () {
      const open = nav.classList.toggle("open");
      this.setAttribute("aria-expanded", String(open));
    });

    links.forEach(function (link) {
      link.addEventListener("click", function () {
        nav.classList.remove("open");
        $("#navToggle").setAttribute("aria-expanded", "false");
      });
    });

    const sections = links
      .map(function (l) { return $(l.getAttribute("href")); })
      .filter(Boolean);

    function onScroll() {
      const y = window.scrollY + 120;
      let current = sections[0];
      let best = -1;
      sections.forEach(function (s) {
        if (s.offsetTop <= y && s.offsetTop > best) {
          best = s.offsetTop;
          current = s;
        }
      });
      links.forEach(function (l) {
        l.classList.toggle("active", l.getAttribute("href") === "#" + current.id);
      });
    }
    window.addEventListener("scroll", onScroll, { passive: true });
    onScroll();
  }

  /* ----------------------------------------------------------- reveal */
  function bindReveal() {
    $$(".panel").forEach(function (el) { el.classList.add("reveal"); });
    if (!("IntersectionObserver" in window)) {
      $$(".reveal").forEach(function (el) { el.classList.add("in"); });
      return;
    }
    const io = new IntersectionObserver(function (entries) {
      entries.forEach(function (en) {
        if (en.isIntersecting) {
          en.target.classList.add("in");
          io.unobserve(en.target);
        }
      });
    }, { threshold: 0.08 });
    $$(".reveal").forEach(function (el) { io.observe(el); });
  }

  /* ------------------------------------------------------------- init */
  document.addEventListener("DOMContentLoaded", function () {
    renderPrograms();
    renderProblems();
    renderQuestions();
    bindAccordion();
    bindViewAll();
    bindTheme();
    bindNav();
    bindReveal();
  });
})();
