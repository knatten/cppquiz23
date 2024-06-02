
## Porting CppQuiz.org questions to C++23

CppQuiz.org is an open source C++ quiz site. If you're unfamiliar with it, you can read more in [its "About" section](https://cppquiz.org/quiz/about/).

All the CppQuiz questions are currently targetting C++17. We need to update them for C++23. Most questions will still have the same answers, we just need to update the explanations and references to the standard. A few questions will also have different answers.

Doing this all by myself is going to take months, so I would very much appreciate some help from the community. To make that as simple as possible, I've created this repository containing all the questions. There is a [directory for each question](/questions), named after the question number. That directory contains the source code of the question in a `.cpp` file, the hint and explanation in `.md` files, as well as a `README.md` explaining everything you need to do to port the question. There's also an issue for each question, making it easier to track progress. The issue has the same information as the `README.md` file.

As soon as we've updated all the questions in this repository, I'll import them back into CppQuiz, and from then on CppQuiz will always ask about C++23.

## How to help

You can help by porting questions or reviewing pull requests:

### Porting questions
First, fork this repo by clicking the "Fork" button at the top right.

If you're a collaborator in this repo, assign some of the issues to yourself, to avoid several people working on porting the same questions. A simple way to do this is to just find a page of [unassigned questions](https://github.com/knatten/cppquiz23/issues?q=is%3Aissue+is%3Aopen+no%3Aassignee), tick the box to select all the questions on that page, and assign them to yourself in one go. Don't worry if you can't finish them all, you can just unassign them later if it takes longer than you expected or you lose interest.

If you're not a collaborator in this repo, just port one question at a time and add a pull request, or ask @knatten to become a collaborator if you want to port many.

Then follow the instructions in the issue to port the question.

### Reviewing pull requests
Pick an open pull request, check that the changes look good and that updated references are correct (point to the right place in the standard, quotes are correct etc.). Ask the contributor for changes if needed, otherwise comment "LGTM" in the pull request. I'll handle merging.

### Other ways to help
- Look for questions labeled `help wanted`. It means the person responsible needs a second pair of eyes.
- Other ideas for help are also welcome, please get in touch (see [Questions](#questions) below).

### Questions
If you have any questions, either file an issue in this repo, contact [@knatten on Twitter](https://twitter.com/knatten), or email me at anders@knatten.org.
