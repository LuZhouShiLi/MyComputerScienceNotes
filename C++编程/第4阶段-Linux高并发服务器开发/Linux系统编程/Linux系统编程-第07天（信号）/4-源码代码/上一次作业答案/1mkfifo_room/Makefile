all:talkA talkB

talkA:talkA.c
	gcc $< -o $@

talkB:talkB.c
	gcc $< -o $@

.PHONY:clean
clean:
	rm -rf talkA talkB fifo*
