run:
	gcc main.c run_simulator.c load.c fetch.c decode_execute.c alu.c -o run

clean:
	rm -f run
