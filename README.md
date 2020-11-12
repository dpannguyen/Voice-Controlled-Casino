# CS 3307 Group 23 Blackjack Game

## Installation Steps

* Install these packages

  ```sh
  sudo apt-get update
  sudo apt-get install build-essential libssl1.0.0 libasound2 wget
  ```

  * If libssl1.0.0 is not available, install libssl1.0.x (where x is greater than 0) or libssl1.1 instead.

## Build the game

* Download and extract the Speech SDK
  * **By downloading the Microsoft Cognitive Services Speech SDK, you acknowledge its license, see [Speech SDK license agreement](https://aka.ms/csspeech/license201809).**
  * Run the following commands after replacing the string `/your/path` with a directory (absolute path) of where the SpeechSDK dir:

    ```sh
    export SPEECHSDK_ROOT="/your/path"
    mkdir -p "$SPEECHSDK_ROOT"
    wget -O SpeechSDK-Linux.tar.gz https://aka.ms/csspeech/linuxbinary
    tar --strip 1 -xzf SpeechSDK-Linux.tar.gz -C "$SPEECHSDK_ROOT"
    ```
* Navigate to the directory of the Makefile of this repository
* Edit the file `Makefile`:
  * In the line `SPEECHSDK_ROOT:=/change/to/point/to/extracted/SpeechSDK` change the right-hand side to point to the location of your extract Speech SDK for Linux.
* Run the command `make` to build the sample, the resulting executable will be called `blackjack`.

## Run the sample

To run the game, you'll need to configure the loader's library path to point to the Speech SDK library.

  ```sh
  export LD_LIBRARY_PATH="$LD_LIBRARY_PATH:$SPEECHSDK_ROOT/lib/x86"
  ```

Run the game:

```sh
./blackjack
```
