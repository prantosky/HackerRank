import re
import sys

input = sys.stdin.read()
question = r'<a href\s?=\s?"/questions/(\d*)/.*?>(.*?)</a>'
relative_time = r'class="relativetime">(.*?)</span>'

found_questions = list()
found_time = list()

for i in re.findall(question, input):
    found_questions.append(i)
for i in re.findall(relative_time, input):
    found_time.append(i)

for i in tuple(zip(found_questions, found_time)):
    print(i[0][0], i[0][1], i[1], sep=';')
