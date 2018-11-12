all: target1 target2
	echo "This is a rule for $@"

#target1: dep
#	echo "This is a rule for $@"
#target2: dep
#	echo "This is a rule for $@"
#use multi-rules to combine target1 and target2
target1 target2: dep
	echo "This is a rule for $@"

dep:
