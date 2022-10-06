# This is a wordle solver that barely works.
Yes, that is what it is. This wordle solver is not what you have seen in the past. Brilliant solutions that implore recursion, AI, algorithms, and actually decent code. This is groundbreaking new technology in how absolutely garbage this runs and just how memory inefficient it is. The point of this solver is to brute force the wordle by generating every possible solution and then check them against the list of actual words. I wrote this in less then 30 minutes in class one day because I ~~couldn't get the wordle one day~~ wanted to test my programming abilities. This led me to spending 5 hours of my weekend dedicated to cleaning it up while I waited in line. I only had my windows laptop so while it works on windows compiling with gcc (mingw), it does not on linux (at least not on Arch). I will not be fixing this because this was for fun. I hope you enjoy this.

Sidenote: I made a quick ui on command line and it breaks for some reason but I'm not going to fix it lol.

# How to run
Insert your known letters into the 'known' field with '.' for unknown letters.

List all unknown letters and tested but not in correct place letters in the 'unknown' field.

If you think a known letter will be reused, put that in 'unknown' as well.
