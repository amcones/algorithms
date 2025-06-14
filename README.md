# algorithms

My algorithm templates. Contains commonly used algorithms and data structures in competitions and academia. Written in
C++20 standard, each algorithm has a runnable test case. Detailed documents are included, explaining various ideas and key implementation points.

See [docs/](.) for detailed documentation, and [content/include/](./content/include) for raw source code of algorithm implementation,
and [content/src/](./content/src) for runnable test cases.

The code in this repository is all under the MIT License, while the documentation, except for the referenced parts, follows the [CC BY-NC 4.0](https://creativecommons.org/licenses/by-nc/4.0/) License.

## Introduction

While learning algorithms, deepen understanding and memory through implementation.

Since learning is a private matter, the code style and description will be more personal. However, code quality will be
guaranteed, allowing the code to be self-explanatory.

## Deployment

The code part of this project is configured by CMAKE and can be compiled and run independently. The documentation part is deployed using [MkDocs](https://github.com/mkdocs/mkdocs) at [amcones.cn/algorithms](https://amcones.cn/algorithms). It can be locally deployed with the following simple configuration.

```bash
git clone https://github.com/amcones/algorithms --depth=1

cd algorithms

# Install mkdocs
pipenv install --pypi-mirror https://pypi.tuna.tsinghua.edu.cn/simple/

# Two methods (choose one):
# 1. Run a local server, access http://127.0.0.1:8000 to view the effect
pipenv run mkdocs serve -v

# 2. Build static page in 'site' folder
pipenv run mkdocs build -v
```

## Contribution

Please check [CONTRIBUTION](CONTRIBUTING.md).

## Copyright Statement

The code part of the project is licensed under the MIT License, which means that this copyright statement and this license statement should be included in all copies or major parts of the software. The software is provided "as is", without any form of warranty.

Except where otherwise specified, all parts of the project except for the code are licensed under [Creative Commons BY-NC 4.0](https://creativecommons.org/licenses/by-nc/4.0/).

In other words, you may freely share and derive from it during use, but you must give attribution and may not use it for commercial purposes.

## Acknowledgments

This project was inspired by [OI Wiki](https://github.com/OI-wiki/OI-wiki), and many materials were referred to during the writing process. Hereby, all due thanks are expressed.

Thank you to all the [contributors](https://github.com/amcones/algorithms/graphs/contributors) for their contributions to this project.
