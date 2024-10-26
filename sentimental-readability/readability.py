from cs50 import get_string

sentc_set = ('.', '!', '?')


def main():
    text = get_string("Text: ")
    letter_num = count_letters(text)
    words_num = count_words(text)
    sentence_num = count_sentences(text)

    l = float(letter_num / words_num * 100)
    s = float(sentence_num / words_num * 100)
    index = round(0.0588 * l - 0.296 * s - 15.8)

    if index < 1:
        print("Before Grade 1")
    elif index >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {index}")


def count_letters(text):
    # To count the letters in the given string
    count = 0
    for i in range(len(text)):
        if text[i].isalpha():
            count += 1
    return count


def count_words(text):
    # To count the words in given string
    count = 0
    for i in range(len(text)):
        if text[i] == " ":
            count += 1
    return (count + 1)


def count_sentences(text):
    # To count the sentences in given string
    count = 0
    for i in range(len(text)):
        if text[i] in sentc_set:
            count += 1
    return count


if __name__ == "__main__":
    main()
