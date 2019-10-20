class Random:    
    def __init__(self, seed):
        self.sevenFive = 16807
        self.twoThirtyone = 2147483647
        self.newNum = seed

    def next(self):
        self.newNum = self.sevenFive*self.newNum % self.twoThirtyone
        return self.newNum

    def choose(self, limit):
        return next()%limit



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
        if left in self.dictionary:
            self.dictionary[left]+=(Rule(left,right),)
        else:
            self.dictionary[left]=(Rule(left, right),)

    def generate(self):
        if 'Start' in self.dictionary:
            self.generating(self.dictionary['Start'])
        else:
            raise RuntimeError

    def generating(self,strings):
        result=''
        for n in range (0, len(strings)):
            if strings[n] in self.dictionary:
                newStr = select(strings[n])
                generating(newStr)
            else:
                result += str(strings[n])
                result += " "
        return result

    def select(self, left):
        rules=self.dictionary[left]
        index=self.r.choose(len(rules))
        



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
G.generate()
G.generate()
G.generate()
G.generate()
G.generate()
