all: Counting.c Scheduling.c 
	@gcc Counting.c -o Counting
	@gcc Scheduling.c -o scheduling
	@sudo ./scheduling
	@python3 Histogram.py
clean:
	@rm SHED_OTHER
	@rm SHED_RR
	@rm SHED_FIFO
	@rm scheduling
	@rm Counting
Histogram:
	@python3 Histogram.py
run: 
	@sudo ./scheduling
	@python3 Histogram.py