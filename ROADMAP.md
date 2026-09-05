# 🗺️ Easiest Roadmap: C Programming Learning Website

A beginner-friendly plan to build a **C programming website** with explanations,
outputs, magic tricks, projects, and quizzes — using **only HTML, CSS, and JavaScript**
(no frameworks, no build tools, no backend). Just a folder of files that link together.

---

## 🎯 What We're Building

| Section | What It Contains |
| :--- | :--- |
| 🏠 **Home** | Welcome + navigation to all sections |
| 📖 **Tutorials** | C topics with explanation + code + output |
| 🎩 **Magic Tricks** | Cool/surprising C tricks (swap without temp, etc.) |
| 🛠️ **Projects** | Mini C projects with source code |
| ❓ **Quiz** | Interactive MCQ quiz with score (JavaScript) |

---

## 📁 Phase 0 — Folder Structure (Day 1)

Everything lives in **one folder**. HTML, CSS, and JS connect directly:

```
c-website/
│
├── index.html          ← Home page
├── style.css           ← All styling (one file keeps it easy)
├── script.js           ← All JavaScript (quiz, menu toggle, etc.)
│
├── tutorials.html      ← C explanations + code + output
├── magic.html          ← C magic tricks
├── projects.html       ← C mini projects
├── quiz.html           ← Interactive quiz
│
└── images/             ← (optional) screenshots, logo
```

**How the files connect** (this is the "directly connected" part):

```html
<!-- Put this inside <head> of EVERY html file -->
<link rel="stylesheet" href="style.css">

<!-- Put this just before </body> of EVERY html file -->
<script src="script.js"></script>
```

**Navigation** connects the pages:

```html
<nav>
  <a href="index.html">Home</a>
  <a href="tutorials.html">Tutorials</a>
  <a href="magic.html">Magic Tricks</a>
  <a href="projects.html">Projects</a>
  <a href="quiz.html">Quiz</a>
</nav>
```

✅ **Checkpoint:** Open `index.html` in a browser, click links, pages switch.

---

## 🏗️ Phase 1 — Build the Home Page (Day 1–2)

1. Create `index.html` with the basic skeleton (`<!DOCTYPE html>`, head, body).
2. Add the **nav bar** (same nav copy-pasted into every page).
3. Add a **hero section**: big title like *"Learn C Programming the Fun Way"*.
4. Add **5 cards** (one per section) that link to the other pages.
5. Link `style.css` and give it simple colors.

**Easiest tip:** Write the nav + footer once, then reuse them in all pages.

✅ **Checkpoint:** Home page looks decent, cards link to the (empty) pages.

---

## 🎨 Phase 2 — Styling with CSS (Day 2–3)

In `style.css`, style in this order (easiest first):

1. **Colors & fonts** — pick 2–3 colors (e.g. dark navy + cyan + white).
2. **Nav bar** — `display: flex` on the nav.
3. **Cards** — border, padding, `hover` effect.
4. **Code blocks** — style `<pre>`/`<code>` with a dark background so C code looks like a terminal:

```css
pre {
  background: #1e1e2e;
  color: #a6e3a1;
  padding: 15px;
  border-radius: 8px;
  overflow-x: auto;
}
```

5. **Mobile-friendly** — add one media query:

```css
@media (max-width: 600px) {
  nav { flex-direction: column; }
}
```

✅ **Checkpoint:** Site looks clean on laptop AND phone.

---

## 📖 Phase 3 — Tutorials Page (Day 3–5)

This is where **explanation + code + output** lives. Use ONE repeating template per topic:

```html
<div class="topic">
  <h2>1. Hello World</h2>
  <p>Explanation: printf() prints text to the screen...</p>

  <h3>📝 Code</h3>
  <pre><code>#include &lt;stdio.h&gt;
int main() {
    printf("Hello, World!");
    return 0;
}</code></pre>

  <h3>💻 Output</h3>
  <pre class="output">Hello, World!</pre>
</div>
```

> ⚠️ Remember: inside HTML, write `<` as `&lt;` and `>` as `&gt;` in code.

**Easy topic order:** Hello World → Variables → Data Types → Input/Output →
If-Else → Loops → Arrays → Strings → Functions → Pointers → Structures.

Add 1–2 topics a day — don't rush. ✅ **Checkpoint:** 5+ topics done.

---

## 🎩 Phase 4 — Magic Tricks Page (Day 5–6)

Same template as tutorials, but each trick = *"How does this even work?!"*

Fun ideas to include:

| Trick | Why It's Magic |
| :--- | :--- |
| Swap two numbers without a third variable | Uses `+`/`-` or XOR |
| Print without `printf` | Uses `puts()` / `write()` |
| Check even/odd without `%` | Uses bitwise `&` |
| `main()` calling itself | Recursion surprise |
| Add without `+` | Bitwise XOR + AND |
| Print 1–100 without loops | Recursion or `goto` |

Format per trick: **Title → The "magic" code → Output → Plain-English explanation of the trick.**

✅ **Checkpoint:** 4–6 tricks, each tested in a real compiler first!

---

## 🛠️ Phase 5 — Projects Page (Day 6–7)

Each project card = **name, what it does, full code, sample output**. Easy C mini-projects:

1. 🧮 Simple Calculator (switch-case)
2. 🔢 Number Guessing Game (rand + loop)
3. 🎓 Student Grade Calculator
4. 💰 ATM Simulator (balance, deposit, withdraw)
5. 📅 Digital Clock / Leap Year Checker

**Tip:** Collapse long code with `<details>` so the page stays clean:

```html
<details>
  <summary>👀 Click to see the code</summary>
  <pre><code>...your C code...</code></pre>
</details>
```

✅ **Checkpoint:** 3+ projects shown with output.

---

## ❓ Phase 6 — Quiz Page with JavaScript (Day 7–9)

This is the only "real programming" part of the website — and it's easier than it looks.

**Step 1:** Store questions in `script.js` as an array:

```javascript
const questions = [
  {
    q: "Which symbol is used to end a statement in C?",
    options: [".", ";", ":", ","],
    answer: 1   // index of the correct option
  },
  {
    q: "Which function prints output in C?",
    options: ["print()", "echo()", "printf()", "cout"],
    answer: 2
  }
];
```

**Step 2:** Add buttons for options in `quiz.html` with empty `<div id="quiz">`.

**Step 3:** JavaScript logic (15–20 lines):
- Show question → user clicks an option → mark right/wrong → next question.
- At the end: show score like *"You scored 7 / 10 🎉"*.
- Add a **Restart** button.

**Step 4:** Add 10 C questions to start; grow to 20 later.

✅ **Checkpoint:** Full quiz works, score shows, restart works.

---

## 🚀 Phase 7 — Publish FREE with GitHub Pages (Day 9–10)

You already know Git & GitHub, so this is 5 minutes:

1. Put the `c-website/` folder in a GitHub repo (e.g. `priyajitpaul4-cmyk/c-website`).
2. Repo → **Settings → Pages → Source: main branch → Save**.
3. Your site goes live at: `https://priyajitpaul4-cmyk.github.io/c-website/`
4. Add the live link to your profile README 🎉

---

## 📅 Simple 10-Day Plan

| Day | Task |
| :--- | :--- |
| 1 | Folder + all 5 HTML pages + navigation |
| 2–3 | Home page + CSS styling |
| 3–5 | Tutorials (1–2 topics per day) |
| 5–6 | Magic tricks page |
| 6–7 | Projects page |
| 7–9 | Quiz with JavaScript |
| 9–10 | Test everything → deploy on GitHub Pages |

---

## ⭐ Golden Rules (to keep it EASY)

1. **One CSS file, one JS file** — shared by all pages. No duplication.
2. **Copy-paste the nav/footer** into every page — don't get fancy.
3. **Test C code in a real compiler** before posting (programiz online compiler is fine).
4. **Small daily commits** — push to GitHub after each work session.
5. **Done > perfect** — launch with a little content, add more later.

---

*Built step by step by Priyajit Paul 🚀*
