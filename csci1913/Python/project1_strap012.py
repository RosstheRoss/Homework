class Random:    
    def __init__(self, seed):
        self.sevenFive = 16807
        self.twoThirtyone = 2147483647
        self.newNum = seed

    def next(self):
        self.newNum = self.sevenFive*self.newNum % self.twoThirtyone
        return self.newNum

    def choose(self, limit):
        return self.next()%limit



class Rule:
    def __init__(self, left, right):
        self.left = left
        self.right = right
        self.count = 1

    def __repr__(self):
        string = str(self.count)
        string += " "
        string += str(self.left)
        string += " -> "
        for n in range (0, len(self.right)):
            string += self.right[n]
            string += " "
        return string



class Grammar:
    def __init__(self, seed):
        self.r = Random(seed)
        self.dictionary = {}

    def rule(self, left, right):
        if left not in self.dictionary:
            self.dictionary[left]=(Rule(left,right),)
        else:
            self.dictionary[left]+=(Rule(left, right),)

    def generate(self):
        if 'Start' in self.dictionary:
           return self.generating(('Start',))
        else:
            raise RuntimeError

    def select(self, left):
        rules=self.dictionary[left]
        total=len(rules)
        index=self.r.choose(total)
        chosen=rules[0] #Debug Kludge
        while index > 0:
            chosen=rules[index]
            index-=rules[index].count
        for n in range (0, len(rules)):
            if rules[n] is not chosen:
                rules[n].count+=1
        return chosen.right

    def generating(self,strings):
        result=''
        for n in range (0, len(strings)):
            if strings[n] not in self.dictionary:
                result += strings[n]
                result += " "
            else:
                result += self.generating(self.select(strings[n]))
        return result




G = Grammar(101)
G.rule('Noun',   ('cat',))  # 01
G.rule('Noun',   ('boy',))  # 02
G.rule('Noun',   ('dog',))  # 03
G.rule('Noun',   ('girl',))  # 04
G.rule('Verb',   ('bit',))  # 05
G.rule('Verb',   ('chased',))  # 06
G.rule('Verb',   ('kissed',))  # 07
G.rule('Phrase', ('the', 'Noun', 'Verb', 'the', 'Noun'))  # 08
G.rule('Story',  ('Phrase',))  # 09
G.rule('Story',  ('Phrase', 'and', 'Story'))  # 10
G.rule('Story',  ('Phrase', 'but', 'Story'))  # 11
G.rule('Start',  ('Story', '.'))  # 12
for n in range (0,5):
    print(G.generate())