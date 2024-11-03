#### Sorting of todo lists

Takes in a file as an argument and output the contents with the completed tasks sorted to the bottom of any list.

A task looks like:
- [ ]
A completed task looks like:
- [x]
Commented lines and other bullet points should be left where they are.

The nested tasks and comments should move with the parent comment.

A list looks like a paragraph of tasks, bullet points and comments.

This
is
a
list
Same list
Some text
New
list
A list could also look like a block of text between two blank lines.

Tests:
my_sorter test_sorter.md
where
test_sorter
complete

not complete

a task

not a task

another task
bullet point

finished task

done

final task

New list

task 1

task 2

task 3

task 4
split list

task a

task b

task c

task d

bullet


should output
expected_sorter
not complete

a task

not a task

another task
bullet point

final task

complete

finished task

done

New list

task 1

task 2

task 4

task 3
split list

task b

task c

task a

task d

bullet


to the console.

Implementation
Objects

Parser - Reads and checks the line and stores/outputs the useful info.
CommandLineArgumentParser - Reads and checks the command line inputs and stores/outputs the useful info
Completed task queue
Token
Task
Comment
Bullet point
File handler?
Processor - Works through the file line by line, storing the completed tasks until it is ready to print
Updated requirements
Indented bullet points should move with the task above
Functional version
