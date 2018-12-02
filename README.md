# Generate Waterfall Diagram from gdb memory dump

To generate memory dump:
```
make waterfall
hexdump out.bin
```

To show diagram:
```
virtualenv venv
source venv/bin/activate
pip install matplotlib
make run_waterfall
```

This should display a diagram window, just as in the [blog post](https://steffen.ronalter.de/2018/12/02/commandline-gdb).
