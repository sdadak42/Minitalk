# Minitalk

**Minitalk** is a small data exchange program developed as part of the 42 School curriculum. It implements a communication channel between a client and a server using UNIX signals.

## 📝 Description

The purpose of this project is to create a communication program in C. The program consists of a **server** and a **client**. The server launches first and prints its PID. The client then takes the server's PID and a string as arguments, and sends the string to the server. The server receives the string and prints it.

The communication is achieved solely using two UNIX signals: `SIGUSR1` and `SIGUSR2`.

## ✨ Features

### Mandatory Part
- **Server**:
  - Starts and prints its PID.
  - Waits for incoming signals.
  - Decodes the received signals into characters and prints the string.
- **Client**:
  - Takes the server's PID and a string as arguments.
  - Converts the string into a series of signals.
  - Sends the signals to the server.
- **Communication**:
  - Uses `SIGUSR1` to represent a `1` bit.
  - Uses `SIGUSR2` to represent a `0` bit.
  - Supports Unicode characters.

### Bonus Part
- **Acknowledgement**: The server sends a signal back to the client to confirm that the message has been fully received.
- **Unicode Support**: Fully supports standard and extended ASCII characters (already implicit in the mandatory part but explicitly handled).

## 🛠️ Compilation

To compile the project, run the following command in the root directory:

```bash
make
```

This will generate two executables: `server` and `client`.

To compile the bonus version (with message acknowledgement), run:

```bash
make bonus
```

This will generate `server_bonus` and `client_bonus`.

## 🚀 Usage

### 1. Start the Server

First, run the server. It will print its PID and wait for messages.

```bash
./server
```
*Output:*
```
Pid: 12345
```

### 2. Run the Client

Open a new terminal window and run the client with the server's PID and the message you want to send.

```bash
./client 12345 "Hello, Minitalk!"
```

The server will print:
```
Hello, Minitalk!
```

### Bonus Usage

If you compiled with `make bonus`:

1. Start the bonus server:
   ```bash
   ./server_bonus
   ```

2. Run the bonus client:
   ```bash
   ./client_bonus <PID> "Hello, Bonus!"
   ```

   The client will receive a confirmation signal and print:
   ```
   Message confirmed by server!
   ```

## ⚙️ Technical Details

- The communication relies on bitwise operations.
- Each character is broken down into 8 bits.
- The client iterates through each bit of every character in the string.
- `SIGUSR1` is sent if the bit is `1`.
- `SIGUSR2` is sent if the bit is `0`.
- The server reconstructs the character bit by bit. Once 8 bits are received, it prints the character and resets the bit counter.
- `usleep` is used to ensure the server has enough time to process each signal.

---

*Developed by **sdadak** for 42 Istanbul.*