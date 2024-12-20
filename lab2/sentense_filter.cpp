#include "sentense_filter.h"

SentenceFilter::SentenceFilter() : source(""), isTextSource(false) {
    cout << "Конструктор по умолчанию для класса SentenceFilter вызван\n";
}

SentenceFilter::SentenceFilter(const string& filename)
    : source(filename), isTextSource(false) {
    cout << "Конструктор без параметров для класса SentenceFilter вызван\n";
}

SentenceFilter::SentenceFilter(const string& text, bool isText)
    : source(text), isTextSource(isText) {
    cout << "Конструктор с параметрами для класса SentenceFilter вызван\n";
}

SentenceFilter::SentenceFilter(const SentenceFilter& other)
    : source(other.source), isTextSource(other.isTextSource) {
    cout << "Конструктор копирования для класса SentenceFilter вызван\n";
}

SentenceFilter::~SentenceFilter() {
    cout << "Деструктор для класса SentenceFilter вызван\n";
}


void SentenceFilter::result() const {
    string text;

    if (isTextSource) {
        text = source;
    } else {
        ifstream file(source);
        if (!file.is_open()) {
            cerr << "Не удалось открыть файл: " << source << endl;
            return;
        }
        ostringstream buffer; //создаем поток для считывания содержимого файла в строку
        buffer << file.rdbuf(); //считываем содержимого потока в строку
        text = buffer.str(); //преобразуем содержимое потока в строку
        file.close();
    }

    cout << "Read text:\n" << text << "\n\n";

    string* lines = nullptr;
    int lineCount = 0;
    split_into_lines(text, lines, lineCount);

    cout << "Текст с замененными словами:\n";
    for (int i = 0; i < lineCount; ++i) {
        cout << swap_adjacent_words(lines[i]) << endl;
    }

    delete[] lines;
}

string SentenceFilter::swap_adjacent_words(const string& line) const {
    regex wordRegex("(\\b\\w+\\b)\\s+(\\b\\w+\\b)");
    string result = regex_replace(line, wordRegex, "$2 $1");
    return result;
}

void SentenceFilter::split_into_lines(const string& text, string*& lines, int& lineCount) const {
    const int maxLines = 100;
    lines = new string[maxLines];
    lineCount = 0;
    istringstream stream(text);
    string line;

    while (getline(stream, line)) {
        if (lineCount < maxLines) {
            lines[lineCount++] = line;
        }
    }
}
