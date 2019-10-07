from subprocess import check_output


tests = [
    ("strlen", "helloworld"),
    ("strcmp", "hello", "nope"), 
    ("memmove",),
]

#
# As you do the assignment, you can put more tests into the tests array.
# Here are a few. Don't forget to separate them with a comma
#
#    ("strcmp", "hello", "hello"),
#    ("strcmp", "hello", "nope"),
#    ("strncmp", "hello", "hello", "3"),
#    ("strchr", "something", "m"),
#    ("memmove",),  #memmove test takes no parameter
#    ("memmove",),  #the comma inside the tuple is important
#    ("memset",),   #same with memset
#    ("strcspn", "haystack has a needle", "needle"),


for test in tests:
    cmd = ["./grade"] + list(test)
    print("test: {}    {}".format(test, "CORRECT" if "1" in str(check_output(cmd)) else "WRONG"))

