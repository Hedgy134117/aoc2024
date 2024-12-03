import re

with open("day3.txt", "r") as f:
    s = f.readline()
    # part 1
    print(
        sum(
            [
                int(pair[0]) * int(pair[1])
                for pair in re.findall(
                    r"mul\((\d{1,3}),(\d{1,3})\)",
                    s,
                )
            ]
        )
    )

    # part 2
    print(
        sum(
            [
                int(pair[0]) * int(pair[1])
                for pair in re.findall(
                    r"mul\((\d{1,3}),(\d{1,3})\)",
                    re.sub(r"don't\(\).*?do\(\)", "", s),
                )
            ]
        )
    )
