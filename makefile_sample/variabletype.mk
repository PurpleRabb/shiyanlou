foo1 = $(bar)
foo2 := $(bar)

bar = $(ugh)
ugh = Hub?

all:
	echo "foo1 is $(foo1), foo2 is $(foo2)" #Hub?
