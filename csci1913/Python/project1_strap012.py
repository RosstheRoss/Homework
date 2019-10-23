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
            self.dictionary[left] = (Rule(left,right),)
        else:
            self.dictionary[left] += (Rule(left, right),)

    def generate(self):
        if 'Start' in self.dictionary:
           return self.generating(('Start',))
        else:
            raise RuntimeError

    def select(self, left):
        rules = self.dictionary[left]
        total = 0
        c = 0
        #Some of the loops are probably not needed
        for m in range (0, len(rules)):
            total += rules[m].count
        index = self.r.choose(total)
        for c in range (0, len(rules)):
            index -= rules[c].count
            if index <= 0:
                break
        chosen = rules[c]
        for n in range (0, len(rules)):
            if rules[n] is not chosen:
                rules[n].count += 1
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
for n in range (0, 5):
    print(G.generate())

# the cat bit the boy .
# the cat kissed the dog and the boy chased the boy .
# the cat chased the dog and the girl bit the boy but the girl chased the cat .
# the girl chased the dog .
# the boy kissed the girl and the cat kissed the girl .

print()
print()

# 
# 

J = Grammar(1453)
J.rule('Noun',   ('sentence',))
J.rule('Noun',   ('walrus',))
J.rule('Noun',   ('sky',))
J.rule('Noun',   ('diamond',))
J.rule('Noun',   ('Ottoman Empire',))
J.rule('Verb',   ('is',))
J.rule('Verb',   ('fanned',))
J.rule('Verb',   ('generated',))
J.rule('Verb',   ('hit',))
J.rule('Phrase', ('the', 'Noun', 'Verb', 'the', 'Noun'))  # 08
J.rule('Phrase', ('Noun', 'Verb', 'the', 'Noun'))
J.rule('Story',  ('Phrase',))  # 09
J.rule('Story',  ('Phrase', 'and', 'Story'))  # 10
J.rule('Story',  ('Phrase', 'but', 'Story'))  # 11
J.rule('Start',  ('Story', '.'))  # 12

for f in range(0, 5):
    print(J.generate())

# the walrus is the sentence and the diamond generated the walrus .
# the walrus generated the walrus and the walrus generated the sentence but diamond hit the sentence .
# sentence fanned the Ottoman Empire .
# the sky hit the diamond and sky is the sentence but the sky fanned the diamond .
# the walrus generated the diamond and the diamond generated the Ottoman Empire but the sky generated the sentence .
