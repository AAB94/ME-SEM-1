Open Terminal

Step 1.
		rpcgen dictionary.x
Step 2.
		rpcinfo if errors occurs install portmap(sudo apt-get install portmap)
Step 3.
		sh compile.sh
Step 4.
		Press Ctrl+Shift+N to open a new terminal.
Step 5. 
		sudo ./server
Step 6.
		./client <server_address>
		eg ./client localhost if run locally.		
Done!
