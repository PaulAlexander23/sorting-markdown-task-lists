# Sorting Markdown task lists

![Test Status](https://github.com/PaulAlexander23/sorting-markdown-task-lists/actions/workflows/c-cpp.yml/badge.svg)

Simple c++ program to sort tasks in a markdown file, so that the completed tasks are at the bottom of the list and the order is preserved.

Markdown tasks are defined as:
```
- [ ] a task
- [ ] another task
- [x] completed task
```
A task is considered completed if it has an 'x' in the brackets.

There are other task statuses that are not currently considered in this program.

## Pre-requisites

None.

## Build

```bash
make 
```

## Usage

To sort the tasks in a file and output the result to the console:
```bash
./my_sorter <input_file> 
```

To sort the tasks in a file and output the result to a file:
```bash
./my_sorter <input_file> > <output_file>
```

## Testing

```bash
make check
```

## License

Distributed under the MIT license. See LICENSE.txt for more information.

## Contributing

Any contributions are welcome.
If you have a suggestion that would make this better, you can also open an issue with the tag "enhancement".
Or if you want to report a bug, you can open an issue with the tag "bug".
Finally, if you want to contribute directly, follow these steps:
1. Fork the project
2. Create your feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a pull request

