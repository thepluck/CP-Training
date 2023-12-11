#!/usr/bin/env python3

"""An interactive local tester for the problem 'Exam'.

Basic usage:

    python3 local_tester.py [solution_command]

For example, 

    python3 local_tester.py ./my_solution.exe
    python3 local_tester.py java MySolution
    python3 local_tester.py python3 my_solution.py

For debugging, your program may print in stderr.

There are additional options which you can use:

    # verbose mode
    python3 local_tester.py --verbose ./my_solution.exe

    # only 5000 exam takes
    python3 local_tester.py -q 5000 ./my_solution.exe
    
    # only allow m to be in the interval [1, 3]
    python3 local_tester.py -m 1 3 ./my_solution.exe
    
    # change the random seed
    python3 local_tester.py -s 1234657890 ./my_solution.exe

You can also combine flags.

    python3 local_tester.py -q 5000 -m 1 3 --verbose ./my_solution.exe

Run the following for more information:

    python3 local_tester.py --help
"""

from argparse import ArgumentParser, RawDescriptionHelpFormatter, REMAINDER
from enum import Enum
from functools import partial
from random import Random
from subprocess import PIPE, Popen
from sys import stderr
from textwrap import dedent
from traceback import format_exc

class JudgingException(Exception):
    def __init__(self, message, *args, **kwargs):
        self.message = message
        super().__init__(*args, **kwargs)

class JudgingFailure(Exception):
    pass

def abbrev(s, n=200, dots='...'):
    s = str(s)
    if len(s) <= n:
        return s
    else:
        rem = n - len(dots)
        r = rem // 2
        l = rem - r
        return s[:l] + dots + s[-r:]

tprint = partial(print, "[LOCAL TESTER]")

def interactor(iinput, ioutput, args):
    class Result(Enum):
        FAIL = 0
        PASS = 1
        GREAT = 2
        PERFECT = 3
        INVALID = -1

    ny = {'N': False, 'Y': True}

    if args.verbose:
        tprint("The arguments are:", args, file=stderr)

    rand = Random(args.seed)
    remtakes = args.takes
    score = 0

    ioutput(remtakes)
    while True:
        # generate a case
        if args.verbose:
            tprint(file=stderr)
            tprint(f"Generating a new test case. {remtakes} takes remaining. Currently solved {score} test cases.", file=stderr)
        m = rand.randint(*args.m)
        a = rand.randint(*args.a)
        b = rand.randint(*args.b)
        n = rand.randint(*args.n)
        if args.verbose:
            tprint(f"Parameters generated: m={m}, a={a}, b={b}, n={n}", file=stderr)
        if not (0 < m < n and 0 < a < b < n):
            raise JudgingFailure(f"Invalid parameters generated: {m, a, b, n}")
        answer = [rand.randrange(2) for i in range(n)]
        known = [True]*m + [False]*(n - m)
        rand.shuffle(known)
        if args.verbose:
            tprint("Given input:", ''.join('?' if not known[i] else 'Y' if answer[i] else 'N' for i in range(n)), file=stderr)
            tprint("Answer key: ", ''.join('Y' if answer[i] else 'N' for i in range(n)), file=stderr)

        def compute_result(take):
            if len(take) != n: return Result.INVALID
            correct = 0
            for i in range(n):
                if take[i] not in ny: return Result.INVALID
                correct += ny[take[i]] == answer[i]
            if correct < a: return Result.FAIL
            if correct < b: return Result.PASS
            if correct < n: return Result.GREAT
            return Result.PERFECT

        # print the case
        ioutput(f"{m} {a} {b} {n}")
        ioutput(''.join('?' if not known[i] else 'Y' if answer[i] else 'N' for i in range(n)))

        # handle takes
        while True:
            token = iinput()
            if token == "DONE": return score

            result = compute_result(token)
            if result == Result.PERFECT and remtakes > 0: score += 1
            remtakes = max(remtakes - 1, 0)

            ioutput(remtakes)
            ioutput(result.name)

            if result == Result.PERFECT:
                break
            if result == Result.INVALID:
                raise JudgingException(f"Invalid token: {abbrev(token)}")


def main():
    # TODO problem title update
    parser = ArgumentParser(
            formatter_class=partial(RawDescriptionHelpFormatter, max_help_position=26),
            description=dedent("""\
                An interactive local tester for the problem 'Exam'.

                Basic usage:

                    python3 local_tester.py [solution_command]

                For example, 

                    python3 local_tester.py ./my_solution.exe
                    python3 local_tester.py java MySolution
                    python3 local_tester.py python3 my_solution.py

                For debugging, your program may print in stderr.

                There are additional options which you can use:

                    # verbose mode
                    python3 local_tester.py --verbose ./my_solution.exe

                    # only 5000 exam takes
                    python3 local_tester.py -q 5000 ./my_solution.exe
                    
                    # only allow m to be in the interval [1, 3]
                    python3 local_tester.py -m 1 3 ./my_solution.exe
                    
                    # change the random seed
                    python3 local_tester.py -s 1234657890 ./my_solution.exe

                You can also combine flags.

                    python3 local_tester.py -q 5000 -m 1 3 --verbose ./my_solution.exe

                Run the following for more information:

                    python3 local_tester.py --help

            """))
    parser.add_argument('-s', '--seed', type=int, default=12345, help='random generator seed (default: %(default)s)')
    parser.add_argument('-m', nargs=2, type=int, default=( 1,  5), metavar=('M1', 'M2'), help='inclusive range of values for m (default: %(default)s)')
    parser.add_argument('-a', nargs=2, type=int, default=( 6, 10), metavar=('A1', 'A2'), help='inclusive range of values for a (default: %(default)s)')
    parser.add_argument('-b', nargs=2, type=int, default=(11, 15), metavar=('B1', 'B2'), help='inclusive range of values for b (default: %(default)s)')
    parser.add_argument('-n', nargs=2, type=int, default=(16, 20), metavar=('N1', 'N2'), help='inclusive range of values for n (default: %(default)s)')
    parser.add_argument('-q', '--takes', type=int, default=262144, metavar='Q', help='the number of takes allowed (default: %(default)s)')
    parser.add_argument('-v', '--verbose', action='store_true', default=False, help='more detailed/verbose interactor output')
    parser.add_argument('command', nargs=REMAINDER, help='The solution command')

    args = parser.parse_args()

    # strip off '--'; 
    command = args.command
    if command and command[0] == '--': command = command[1:]

    if not command:
        parser.print_help()
        return

    proc = Popen(command, stdin=PIPE, stdout=PIPE)

    encoding = 'utf-8'

    def iinput():
        return proc.stdout.readline().decode(encoding).rstrip('\r\n')

    def ioutput(line):
        proc.stdin.write(str(line).encode(encoding))
        proc.stdin.write('\n'.encode(encoding))
        proc.stdin.flush()

    try:
        score = interactor(iinput, ioutput, args)
    except JudgingException as exc:
        tprint(exc.message, file=stderr)
        tprint("The interaction failed.")
        exit(1)
    except Exception as exc:
        tprint(file=stderr)
        tprint(file=stderr)
        for line in format_exc().splitlines():
            tprint("    ", line, file=stderr)
        tprint(file=stderr)
        tprint(file=stderr)
        tprint("The tester crashed! See the log above.", file=stderr)
        tprint("The interaction failed.")
        exit(2)
    else:
        # wait for the submission to finish
        proc.communicate()
        tprint(f"s={score} test cases were solved within the first q={args.takes} takes.")
        tprint("The interaction completed successfully.")


if __name__ == '__main__': main()
