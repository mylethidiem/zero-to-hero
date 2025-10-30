<!-- 
🎉 Congratulations on submitting your PR!

Please provide a clear, concise summary of your contribution. 
Once merged, this title and description will appear in the release notes, 
so ensure it accurately reflects the feature and its purpose.
-->

## 🧩 Summary

<!-- Briefly describe what this PR changes or introduces. -->
Fixes # (issue number, if applicable)

Example:
> This PR adds support for exporting models to ONNX and improves the inference pipeline for faster deployment.

---

## 💡 Motivation & Context

<!-- 
Why is this change needed? 
Does it fix a limitation, improve usability, add a new capability, or refactor an existing module?
-->
Example:
> This feature enables users to integrate the model with external inference frameworks and improves compatibility across environments.

---

## 🔍 Changes Overview

<!-- 
List the main modifications introduced by this PR.
-->
- Implemented new `FeatureX` class for ...
- Refactored `utils/io.py` for modularity
- Added configuration flag `--enable-feature-x`
- Updated docs and examples

---

## 🚀 Usage

- Usage remains the same.  
- No external dependencies or parameters changed.

> If behavior changes, update relevant examples or documentation.

---

## 🧪 Testing & Validation

<!-- 
Explain how you validated this change (unit tests, integration tests, manual validation, etc.).
Include sample commands or datasets used for testing.
-->

**Test Coverage**
- [ ] Added/updated unit tests  
- [ ] Verified existing test suite passes  
- [ ] Manually tested feature behavior  

**Example Command**
```bash
pytest tests/test_feature_x.py -v
````

---

## 📚 Documentation

<!-- 
Did you update documentation, examples, or READMEs? 
Link any relevant PRs, guides, or markdown files.
-->

* [ ] Updated user documentation
* [ ] Added/modified docstrings or tutorials
* [ ] No documentation changes needed

> 📘 If documentation updates are large, link the PR or commit here for reviewers’ convenience.

---

## ✅ GitHub Actions / CI Checks

**Before marking as “Ready for review”, please ensure:**

* [ ] Added or updated relevant tests (if applicable)
* [ ] Updated necessary documentation
* [ ] Verified optional dependencies (Numba, Pynini, Apex, etc.)
* [ ] Reviewer: check optional import guards are correct

---

## 🧱 PR Type

Please check the appropriate type:

* [x] New Feature
* [ ] Bugfix
* [ ] Documentation

> *If still a work in progress, mark this PR as “Draft”.*

---

## ✅ Pre-Submission Checklist

Before requesting a review, please confirm the following:

* [ ] Discussed or approved via a GitHub issue or RFC
* [ ] Code follows the project’s style guidelines
* [ ] Tests added/updated where applicable
* [ ] All CI checks pass locally
* [ ] PR title and description are clear and descriptive

---

## 👀 Who can review?

Anyone in the community is welcome to review after checks pass.
Refer to [Contributor guidelines]() for code ownership and review areas.

| Area            | Reviewer     |
| --------------- | ------------ |
| Core / General  | @mylethidiem |
| Docs / Examples | @mylethidiem |
| DevOps / CI     | @mylethidiem |

> 🕐 If your PR hasn’t been reviewed within a week, kindly @-mention the same reviewer(s) again — sometimes notifications get lost.

---

## 🔗 Additional Information

* Related issue(s): `#<issue_number_if_any>`
* Future work: Add visualization or notebook integration for training examples.

---

## 📎 Notes & Attachments

<!-- 
Include related PRs, screenshots, design docs, benchmark results, or references that may help reviewers understand context.
-->

Example:

* Related PR: #123
* Screenshot showing new UI option
* Benchmark: ~25% improvement in inference speed

---

🙌 **Thank you for your contribution!**
Your effort helps make this project better for everyone 💙
