
## Porting CppQuiz.org questions to C++23

CppQuiz.org is an open source C++ quiz site. If you're unfamiliar with it, you can read more in [its "About" section](http://cppquiz.org/quiz/about/).

All the CppQuiz questions are currently targetting C++17. We need to update them for C++23. Most questions will still have the same answers, we just need to update the explanations and references to the standard. A few questions will also have different answers.

Doing this all by myself is going to take months, so I would very much appreciate some help from the community. To make that as simple as possible, I've created this repository containing all the questions. There is a [directory for each question](/questions), named after the question number. That directory contains the source code of the question in a `.cpp` file, the hint and explanation in `.md` files, as well as a `README.md` explaining everything you need to do to port the question. There's also an issue for each question, making it easier to track progress. The issue has the same information as the `README.md` file.

As soon as we've updated all the questions in this repository, I'll import them back into CppQuiz, and from then on CppQuiz will always ask about C++23.

### How to help porting questions
There are two ways to contribute, listed below. I prefer the first alternative, but if that prevents you from contributing, the second is also ok.

#### Contributing using a fork and pull requests
1. Fork this repo by clicking the "Fork" button at the top right.
1. Pick the issue for a question you want to port. Add a comment that you'll be handling that issue.
1. Follow the instructions in the issue to port the question.
1. Make a pull request. Porting several questions in one PR is fine.

#### Contributing without a fork
If you think forking and PRs is too cumbersome, or you are not able to do this for other reasons, I'd still appreciate your help:
1. Pick the issue for a question you want to port. Add a comment that you'll be handling that issue.
1. Follow the instructions in the issue to port the question.
1. Paste the updated files as comments to the issue.

### Other ways to help
- Look for questions labeled `help wanted`. It means the person responsible needs a second pair of eyes.
- Look at pull requests, review them and comment `LGTM` if they should be merged.
- Other ideas for help are also welcome, please get in touch (see [Questions](#questions) below).

### Questions
If you have any questions, either file an issue in this repo, contact [@knatten on Twitter](https://twitter.com/knatten), or email me at anders@knatten.org.
