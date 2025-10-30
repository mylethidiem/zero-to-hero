---
name: 🐞 Dev Container - Bug Report
description: Report a Dev Container issue or unexpected behavior
title: '[Bug]: '
labels: ['bug', 'dev-container']
assignees: []

# Update the container pull date below (format: MM/DD/YYYY)
container_pulled_date: 'MM/DD/YYYY'
---

## 🐛 Describe the Bug
Provide a clear and concise description of the issue.  
Include what went wrong, error messages, or unexpected behavior.

---

## 🔁 Steps to Reproduce
Please include **minimal, self-contained steps** or a short code snippet.

1. [ ] Go to '...'
2. [ ] Click on '....'
3. [ ] Run '....'
4. [ ] See error (e.g., `Error: Something failed`)

> 💡 **Reference:** [How to write minimal bug reports](http://matthewrocklin.com/blog/work/2018/02/28/minimal-bug-reports)

If this involves configuration, attach the relevant part of your `.devcontainer/devcontainer.json`:

```json
// Paste snippet here
````

---

## ✅ Expected Behavior

Describe what you expected to happen instead.

---

## ⚠️ Current Behavior

If different from above, explain what actually happens.
Include stack traces or console output if available:

```
Error traceback or relevant output here
```

---

## 🧩 Environment Details

| Item                         | Your Info                                                             |
| ---------------------------- | --------------------------------------------------------------------- |
| **Host OS**                  | e.g., Windows 11 / macOS Ventura / Ubuntu 22.04                       |
| **VS Code Version**          | e.g., 1.85.0                                                          |
| **Dev Containers Extension** | e.g., v0.300.0                                                        |
| **Docker Version**           | e.g., Docker Desktop 4.25.0                                           |
| **Installation Method**      | e.g., `devcontainer up`, `devcontainer build`, or manual `docker run` |
| **Docker Commands Used**     | `docker pull <image-name:tag>` <br> `docker run <full-command>`       |
| **Container Pulled Date**    | MM/DD/YYYY                                                            |

> If using a remote host, GPU, or cloud environment, please note that as well.

---

## 🧾 Logs & Diagnostics

Attach or paste relevant logs.

* Run **“Dev Containers: Export Logs”** from the Command Palette (`Ctrl+Shift+P`) and attach the file, **or**
* Include output from `docker logs <container-id>`.

If long, include key excerpts only:

```
[Log excerpt]
```

---

## 💥 Impact Level

Please check one:

* [ ] 🟥 Blocks me from using the container entirely
* [ ] 🟧 Affects specific features (describe below)
* [ ] 🟨 Minor inconvenience

Describe briefly if partial functionality still works.

---

## 🧰 Workarounds

If you’ve found a temporary fix or workaround, describe it here.
This helps others until a permanent fix is available.

---

## 🧠 Additional Context

Add any other details that might help us diagnose the issue:

* GPU model or hardware info (e.g., NVIDIA RTX 3080)
* Custom configurations, VS Code extensions, or environment variables
* Related issues or pull requests

---

## 📸 Screenshots / Videos

If applicable, drag-and-drop screenshots or short videos here.
You can use Loom or GitHub’s built-in upload.

---

## ✅ Quick Checklist

* [ ] I’ve reproduced this issue using the **latest** container/image
* [ ] I’ve checked for **duplicate issues**
* [ ] I’ve attached **logs and configuration snippets**
* [ ] I’ve updated the **Container Pulled Date** in the frontmatter

---

🙌 **Thank you for your report!**
Your feedback helps us continuously improve the Dev Container experience.
