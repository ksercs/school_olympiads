import random
random.seed("basic01/knumbers")

class TestGen:
    def __init__(self):
        self.test_number = 0

    def generate_samples(self):
        self.print_test(1, 4321)
        self.print_test(2, 1234)
        self.print_test(3, 123)
        
    def generate_min_tests(self):
        self.print_test(1, 1)
        self.print_test(1, 5)
        self.print_test(1, 9)
        self.print_test(2, 5)
        self.print_test(1, 19)
        self.print_test(2, 19)
        self.print_test(1, 11)
        self.print_test(1, 12)
                                                                    
    def generate_hand_tests(self):
        self.print_test(1, 998)
        self.print_test(1, 999)
        self.print_test(1, 8197)
        self.print_test(1, 8799)
        self.print_test(1, 8999)
        self.print_test(1, 8912)
        self.print_test(1, 8900)
        self.print_test(10, 123)
        self.print_test(3, 2341)
        self.print_test(3, 645231)
        self.print_test(1, 12308912309182309999999999999999999999999999999999999)
        self.print_test(2, 12308912309182309999999999999999999999999999999999999)
        self.print_test(3, 12308912309182309999999999999999999999999999999999999)
        self.print_test(1, 99000000000000000000000000000000000000000000000000000)
        self.print_test(1, 90000000000000000000000000000000000000000000000000000)
        self.print_test(2, 264)
        self.print_test(3, 2155545555555)
        self.print_test(3, 41371111111111)

    def randint(self, l, r):
        return chr(random.randint(ord(l) - ord('0'), ord(r) - ord('0')) + ord('0'))

    def generate_random_test(self, maxn):
        n = maxn
        k = random.randint(1, 10)
        s = ""
        s += self.randint('1', '9')
        for i in range(n - 1):
            s += self.randint('0', '9')
        self.print_test(k, s)

    def random_without(self, maxn, element):
        answer = ""
        for i in range(maxn):
            new_element = self.randint('0', '9')
            while new_element == element:
                new_element = self.randint('0', '9')
            answer += new_element
        return answer

    def generate_max_tests(self, maxn):
        self.print_test(1, ''.join("1" + "9" * (maxn - 1)))
        self.print_test(1, ''.join("9" + "0" * (maxn - 1)))
        self.print_test(3, "21" + self.random_without(maxn - 2, 1))
        self.print_test(3, "4137" + self.random_without(maxn - 4, 3))
        self.print_test(9, self.random_without(maxn, 10))
        self.print_test(8, self.random_without(maxn, 10))
        self.print_test(7, self.random_without(maxn, 10))
        threes_nines_ones = list("9" * (maxn // 3) + "3" * (maxn // 3) + "1" * (maxn // 3))
        random.shuffle(threes_nines_ones)
        self.print_test(3, ''.join(threes_nines_ones))
        self.print_test(2, ''.join(threes_nines_ones))
        self.print_test(1, ''.join(threes_nines_ones))

    def print_test(self, k, s):
        self.test_number += 1
        print('Generating test #%d' % self.test_number)

        test_name = "../tests/" + "{0:0=2d}".format(self.test_number)
        test_file = open(test_name, "w")
        print(k, file=test_file)
        s = str(s)
        if ord(s[0]) == ord('0'):
            s = "1" + s[1:]
        print(str(s), file=test_file)
        test_file.close()

    def generate_all_tests(self):
        self.generate_samples()
        self.generate_min_tests()
        self.generate_hand_tests()
        
        for i in range(5):
            self.generate_random_test(100)
        for i in range(5):
            self.generate_random_test(10000)
        for i in range(5):
            self.generate_random_test(1000000)
        self.generate_max_tests(1000000)        

import os, shutil
if os.path.exists('../tests'):
    print('Directory tests already exists')
    shutil.rmtree('../tests', ignore_errors=False, onerror=None)
try:
    os.makedirs('../tests')
except OSError:
    pass

import time
start = time.time()
writer = TestGen()
writer.generate_all_tests()
finish = time.time()
print('All tests were generated. Elapsed time: ', finish - start)
