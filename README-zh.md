# algorithms

我的算法模版。包含了竞赛、学术中常用的算法与数据结构。以 C++20 标准编写，每个算法都有可运行的测试用例。附有详细文档，讲解各种思想、实现要点。

查看 [docs/](docs) 以获得详细文档，[content/include/](content/include) 以获得算法源代码实现，[content/src/](content/src) 以获得可运行的测试用例。

## 简介

在学习算法的同时，通过实现的方式来深化理解和记忆。

由于学习是件私人的事情，所以在代码风格、描述等方面会比较个人。但代码质量会有所保证，让代码能够做到自解释。

## 部署

本项目中代码部分均由 CMAKE 配置，可自行编译运行。文档部分使用 [MkDocs](https://github.com/mkdocs/mkdocs) 部署在 [amcones.cn/algorithms](https://amcones.cn/algorithms)。可以通过以下简单配置在本地部署。

```bash
git clone https://github.com/amcones/algorithms --depth=1

cd algorithms

# 安装 mkdocs
pipenv install --pypi-mirror https://pypi.tuna.tsinghua.edu.cn/simple/

# 两种方法（选其一即可）：
# 1. 运行一个本地服务器，访问 http://127.0.0.1:8000 可以查看效果
pipenv run mkdocs serve -v

# 2. 在 site 文件夹构建静态页面
pipenv run mkdocs build -v
```

## 参与建设

请查看 [如何参与](CONTRIBUTING.md)。

## 版权声明

项目中代码部分使用 MIT 协议进行许可，即本版权声明和本许可声明应包含在软件的所有副本或主要部分中。软件按“原样”提供，不提供任何形式的保证。

除特别注明外，项目中除了代码部分均采用 [(Creative Commons BY-NC 4.0) 署名—非商业性使用 4.0 国际许可协议](https://creativecommons.org/licenses/by-nc/4.0/) 进行许可。

换言之，使用过程中您可以自由地共享、演绎，但是必须署名，且不得用于商业用途。

## 鸣谢

本项目受 [OI Wiki](https://github.com/OI-wiki/OI-wiki) 的启发，在编写过程中参考了诸多资料，在此一并致谢。

感谢为本项目贡献的所有 [贡献者们](https://github.com/amcones/algorithms/graphs/contributors)。
