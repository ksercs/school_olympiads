import random
random.seed("basic01/cinema")

class TestGen:
    def __init__(self):
        self.test_number = 0

    def generate_samples(self):
        self.print_test(3, 1, 1)
        self.print_test(3, 1, 2)
        
    def generate_min_tests(self):
        self.print_test(1, 1, 1)
        self.print_test(1, 1, 2)
        self.print_test(1, 2, 1)
        self.print_test(1, 1, 1000)
        self.print_test(3, 1000, 1)
        self.print_test(5, 1, 1)
        self.print_test(5, 1, 2)
        self.print_test(5, 2, 1)
        self.print_test(5, 2, 2)
        self.print_test(5, 2, 3)
        self.print_test(5, 3, 2)
        self.print_test(5, 3, 3)
                                                                    
    def generate_hand_tests(self):
        pass

    def generate_random_test(self, maxn):
        n = random.randint(1, (maxn - 1) // 2 + 1) * 2 + 1
        a = random.randint(1, n // 2)
        b = random.randint(1, n // 2)
        if random.randint(1, 2) == 1:
            if random.randint(1, 2) == 1:
                a = n // 2 + 1
            if random.randint(1, 2) == 1:
                b = n // 2 + 1
        self.print_test(n, a, b)                

    def generate_max_tests(self, maxn):
        n = maxn
        if n % 2 == 0:
            n -= 1
        a = n // 2
        b = n // 2
        self.print_test(n, a, b)
        self.print_test(n, a - random.randint(1, 5), b)
        self.print_test(n, a, b - random.randint(1, 5))
        self.print_test(n, a - random.randint(1, 5), b - random.randint(1, 5))

    def print_test(self, n, a, b):
        self.test_number += 1
        print('Generating test #%d' % self.test_number)

        test_name = "../tests/" + "{0:0=2d}".format(self.test_number)
        test_file = open(test_name, "w")
        print(n, a, b, file=test_file)
        test_file.close()

    def generate_all_tests(self):
        self.generate_samples()
        self.generate_min_tests()
        self.generate_hand_tests()
        
        for i in range(5):
            self.generate_random_test(50)
        for i in range(5):
            self.generate_random_test(300)
        for i in range(5):
            self.generate_random_test(1000)
        self.generate_max_tests(1000)

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
