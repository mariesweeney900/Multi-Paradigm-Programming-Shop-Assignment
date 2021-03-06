{
  "nbformat": 4,
  "nbformat_minor": 0,
  "metadata": {
    "colab": {
      "name": "CShopOOP.py",
      "provenance": [],
      "collapsed_sections": [],
      "authorship_tag": "ABX9TyMOz2/mpaG507uy7Ldv1iVC",
      "include_colab_link": true
    },
    "kernelspec": {
      "name": "python3",
      "display_name": "Python 3"
    }
  },
  "cells": [
    {
      "cell_type": "markdown",
      "metadata": {
        "id": "view-in-github",
        "colab_type": "text"
      },
      "source": [
        "<a href=\"https://colab.research.google.com/github/mariesweeney900/Multi-Paradigm-Programming-Shop-Assignment/blob/main/CShopOOP_py.py\" target=\"_parent\"><img src=\"https://colab.research.google.com/assets/colab-badge.svg\" alt=\"Open In Colab\"/></a>"
      ]
    },
    {
      "cell_type": "code",
      "metadata": {
        "id": "p1Sd8Ej5AOOP"
      },
      "source": [
        "#https://www.dummies.com/programming/c/c-programming-how-to-use-pointers-in-functions/\r\n",
        "#include <stdio.h>\r\n",
        "#include <stdlib.h>\r\n",
        "\r\n",
        "struct Product {\r\n",
        "\tchar* name;\r\n",
        "\tdouble cost;\r\n",
        "};\r\n",
        "\r\n",
        "void passDirect(struct Product p)\r\n",
        "{\r\n",
        "\tp.cost = 1000.0;\r\n",
        "}\r\n",
        "\r\n",
        "void passPointer(struct Product* p);\r\n",
        "\r\n",
        "int main()\r\n",
        "{\r\n",
        "\t// These are two of the product types\r\n",
        "\tstruct Product a = { \"Coke Can\", 1.10 };\r\n",
        "\tstruct Product* b = &a;\r\n",
        "\r\n",
        "\tpassDirect(a);\r\n",
        "\tprintf(\"Cost price is %.2f\\n\", a.cost);\r\n",
        "\tpassPointer(b);\r\n",
        "\tprintf(\"Cost price is now %.2f\\n\", a.cost);\r\n",
        "\r\n",
        "}\r\n",
        "\r\n",
        "void passPointer(struct Product* p)\r\n",
        "{\r\n",
        "\tp->cost = 1000.0;\r\n",
        "} "
      ],
      "execution_count": null,
      "outputs": []
    },
    {
      "cell_type": "code",
      "metadata": {
        "id": "6vy6hd6LANbG"
      },
      "source": [
        ""
      ],
      "execution_count": null,
      "outputs": []
    }
  ]
}
