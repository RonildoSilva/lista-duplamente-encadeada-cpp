# Lista duplamente encadeada com templates em C++

> Lista duplamente encadeada genérica (`DCList<Type>`) com serialização de e para JSON, escrita apenas com headers.

![status](https://img.shields.io/badge/status-concluído-success) ![cpp](https://img.shields.io/badge/C%2B%2B-14-blue) ![qt](https://img.shields.io/badge/build-qmake-green)

## Sobre
Questão 1 de um processo seletivo (2019). O objetivo era implementar em C++ uma lista duplamente encadeada com operações básicas e carregar/salvar seu conteúdo em arquivo JSON, sem bibliotecas externas. O parser JSON usa expressões regulares da biblioteca padrão e especialização de templates para `int`, `float` e `std::string`.

## Stack
- C++14, biblioteca padrão (`<regex>`, `<type_traits>`)
- Projeto qmake (`.pro`), criado no Qt Creator 4.8

## Estrutura de pastas
```text
datastructure/dclist.hpp   DCList<Type>: pushFront, pushBack, popFront, popBack, find, isEmpty, show
datastructure/node.hpp     Node<Type> com ponteiros previous/next
template/object.hpp        Object<Type>, invólucro do valor armazenado
jsonparser/jsonparser.hpp  JsonParser<Type>: jsonFileToDSList, DSListToJson, put_int/float/string
input/content.json         arquivo de entrada de exemplo
main.cpp                   demonstração
```

## Como executar
```bash
qmake selecaoFFQuestao01.pro && make
./selecaoFFQuestao01
# ou, sem Qt:
g++ -std=c++14 -I. main.cpp -o lista && ./lista
```

## Status
Concluído.

## Autor
Ronildo Silva · ronildo.comp@gmail.com
