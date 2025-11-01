# Zero to Hero: From Beginner to AI Pro

[![Python](https://img.shields.io/badge/Python-Deep%20Dive-blue)](https://www.udemy.com/course/python-3-deep-dive-part-1/) [![Git](https://img.shields.io/badge/Git-Collaboration-green)](https://git-scm.com/) [![Kaggle](https://img.shields.io/badge/Kaggle-Data%20Science-orange)](https://www.kaggle.com/banhmuy) [![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

Welcome to **Zero to Hero**! This repository chronicles my self-taught journey from coding novice to proficient in Data Science and Artificial Intelligence. It's a structured roadmap packed with curated resources, practical tips, code examples, and collaboration guidelines. Whether you're starting from scratch or refining your skills, use this as your blueprint to level up.

> **Mission:** Transform "zero" knowledge into "hero" expertise through consistent learning, hands-on practice, and team-ready habits. Fork it, contribute, or adapt it for your own path!

## Table of Contents
- [Introduction](#introduction)
- [Learning Overview](#learning-overview)
  - [C++](#c++)
  - [Git](#git)
  - [Python](#python)
  - [Data Science & AI](#data-science--ai)
- [Practice Projects & Profiles](#practice-projects--profiles)
- [Collaboration Guidelines](#collaboration-guidelines)
  - [Commit Message Conventions](#commit-message-conventions)
  - [Git Workflow Rules](#git-workflow-rules)
- [How to Contribute](#how-to-contribute)
- [Certificates](#certificates)
- [License](#license)

## Introduction
This repo serves as both a personal learning log and a public resource hub. Key focus areas:
- **Foundations:** Programming basics (C++, Python) and version control (Git).
- **Advanced Skills:** Data manipulation, machine learning, and AI deployment.
- **Real-World Application:** Links to portfolios, challenges, and projects.
- **Best Practices:** Guidelines for clean code, teamwork, and efficient workflows.

Started in 2024, updated as of October 2025. Track progress via commit history—each update marks a milestone!

## Learning Overview
Step-by-step resources with milestones and pro tips. Prioritize free/open-access materials where possible.

### C++
**Focus:** Build core programming intuition—variables, loops, functions, OOP, and performance tuning. Ideal for systems-level understanding.

- **Resources:**
  - [DaynhaUHoc C++](https://cpp.daynhauhoc.com/) (Free, beginner-friendly in Vietnamese).
  - Udemy: "Beginning C++ Programming - From Beginner to Beyond".
  - NVNS Academy: Advanced modules on STL and multithreading.
- **Milestones:**
  - Compile/run a "Hello World" program.
  - Implement arrays, pointers, and classes.
  - Solve 10+ problems on HackerRank C++ track.
- **Pro Tip:** Use Valgrind for memory debugging—catches leaks early.

### Git
**Focus:** Master version control to collaborate without chaos. From solo commits to PRs in large teams.

- **Resources:**
  - [Official Git Documentation](https://git-scm.com/book/en/v2) (Free, in-depth guide).
  - [Git - The Simple Guide](https://rogerdudler.github.io/git-guide/) (Quick reference).
  - [Best Git Practices for Teams](https://www.geeksforgeeks.org/git/best-git-practices-to-follow-in-teams/) (Workflow strategies).
  - Video: [Quản lý Phiên Bản Code với Git/GitHub](https://www.youtube.com/watch?v=LbNd2XgWFe0) (Practical Vietnamese tutorial).
- **Milestones:**
  - Set up a local repo, add commits, and push to GitHub.
  - Create/merge branches and resolve conflicts.
  - Automate with GitHub Actions for linting/tests.
- **Pro Tip:** Adopt semantic versioning (SemVer) for releases: MAJOR.MINOR.PATCH.

### Python
**Focus:** Versatile language for automation, data analysis, and ML. Emphasize readable, modular code.

- **Resources:**
  - Udemy: [Python 3 Deep Dive (Parts 1-4)](https://www.udemy.com/course/python-3-deep-dive-part-1/) (Comprehensive, from basics to advanced topics like iterators and context managers).
  - [PEP 8 Style Guide](https://peps.python.org/pep-0008/) (Enforce clean, professional code).
- **Milestones:**
  - Write scripts for file handling and APIs.
  - Build a CLI tool with argparse.
  - Optimize with list comprehensions and decorators.
- **Pro Tip:** Lint with Black and Flake8—keeps code consistent across teams.

### Data Science & AI
**Focus:** Turn data into insights. Cover stats, ML algorithms, neural networks, and ethics.

- **Resources:**
  - [AIVN Academy](https://aivietnam.edu.vn) (Vietnamese-focused courses on ML fundamentals).
  - Additional: Udemy (ML A-Z), Coursera (Deep Learning Specialization), Kaggle Learn (Free micro-courses), AWS/NVIDIA (Cloud AI certs).
- **Milestones:**
  - EDA on a Kaggle dataset with pandas/Seaborn.
  - Train/deploy a scikit-learn model.
  - Experiment with TensorFlow/PyTorch for image classification.
- **Pro Tip:** Version experiments with MLflow—tracks params, metrics, and artifacts.

## Practice Projects & Profiles
Apply knowledge through challenges and portfolios. Here's my progress:

- 📊 **[Kaggle Profile](https://www.kaggle.com/banhmuy)**: Notebooks on regression, NLP, and competitions (e.g., Titanic survival prediction).
- 🤖 **[DeepML Profile](https://www.deep-ml.com/profile/mzOHLfAKLVauQjHcZOdJxLdgiTS2)**: Collaborative AI models, including GANs for data augmentation.
- 💻 **[LeetCode Profile](https://leetcode.com/lethidiemmy961996)**: 200+ solved problems in arrays, trees, and dynamic programming.
- 🐵 **[DataLemur - Ace the SQL & Data Science Interview](https://t.co/JG4qmAAbho)**(No profile page): Practice the most common SQL, Statistics, ML, and Python questions asked in FAANG Data Science & Data Analyst interviews!

**Starter Project Ideas:**
- **C++/Git:** Version a simple calculator app with feature branches.
- **Python/DS:** Web scraper for stock data + visualization dashboard.
- **AI:** Fine-tune a Hugging Face model for sentiment analysis on Vietnamese text.

## Collaboration Guidelines
Open to PRs! These rules ensure smooth, professional teamwork.

### Commit Message Conventions
Imperative style with module prefixes for traceability.

**Format:** `[Module]: [Action verb] [Brief description]`

| ✅ **Examples (Do)** | ❌ **Examples (Don't)** |
|---------------------|------------------------|
| `Scripts: Update batch files for faster processing` | `Scripts: fixed paths` |
| `Powershell: Add folder size calculation function` | `update feature` |
| `Data: Refactor CSV parsing to handle edge cases` | `added file` |

**Best Practices:**
- Verbs: Add, Fix, Update, Refactor, Remove, Optimize.
- Capitalize first letter; no trailing period.
- Body (optional): Blank line + details (e.g., "Resolves #42. Improves runtime by 15%.").

### Git Workflow Rules
GitFlow-inspired: `dev` as integration branch, `main` for releases.

1. **Branching:**
   - Default: Work on `dev`.
   - No direct commits to `main` (except tags).
   - Naming: `feature/<name>` (e.g., `feature/user-auth`), `fix/<issue>` (e.g., `fix/api-bug`).

2. **Commit & Push:**
   - `git pull` upstream before `git push` to sync.
   - Follow conventions; no large files/secrets (.env).
   - Use `git add -p` for selective staging.

3. **Pull Requests:**
   - From your branch to `dev`.
   - Description: Goal, changes, tests passed, screenshots if UI-related.
   - @tag reviewers; aim for 1-2 approvers.

4. **Conflicts:**
   - Resolve locally, rebase if needed, test fully.
   - Unsure? Open an issue for guidance.

5. **Structure & Ignores:**
   - Folders: `src/` (code), `tests/` (unit tests), `docs/` (notes).
   - Files: Descriptive names (e.g., `data_loader.py`).
   - `.gitignore`: Temps, models, large CSVs—use [GitHub's template](https://github.com/github/gitignore).

## How to Contribute
1. Fork/clone the repo.
2. Branch: `git checkout -b feature/your-contribution`.
3. Commit/push following guidelines.
4. Open PR to `dev`—include motivation and impact.
5. Discuss via issues for features or bugs.

Your contributions make this repo stronger—thanks for joining the journey!

## Certificates
Key achievements validating the "Hero" status:

1. [Kaggle: Python](https://www.kaggle.com/learn/certification/banhmuy/python) – Core programming skills.
2. [Kaggle: Pandas](https://www.kaggle.com/learn/certification/banhmuy/pandas) – Data wrangling expertise.
3. [CodeLearn Profile](https://codelearn.io/profile/920858) – Algorithms and web challenges.

## License
MIT License – Free to use, modify, and distribute. See [LICENSE](LICENSE) for details. © 2024-2025 [Your Name]. 🚀

