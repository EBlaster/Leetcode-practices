def textQueries(sentences, queries):
    words = []
    for i in range(len(sentences)):
        words.append(sentences[i].split())
    print(words)
    result = []
    for query in queries:
        times = 100000
        appeared = False
        for sent in words:
            print(sent.count(query))
