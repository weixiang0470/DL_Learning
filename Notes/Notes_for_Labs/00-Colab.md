# Colab common uses command
1. `import torch`
    - `torch.cude.is_available()`
- `!`
    - For shell script, starts a new shell, does the operations, and then kills that shell
    - `%` : magic commad
        - Affects the process associated with the notebook
        - use this for `cd` (change directory) command 
2. `!nvidia-smi`
    - to check the allocated CPU type, T4 > K80
3. `!gdown --fuzzy drive_link --output target_output_name`
    - This will download the file/image from **drive_link** and output as **target_output_name**
4. Use javascript to click on connect button on every 60 seconds, from [Stack overflow](https://stackoverflow.com/questions/57113226/how-can-i-prevent-google-colab-from-disconnecting)
    - Open developer settings and type in the console prompt
        - Mac : Option + Command + I
        - Windows : Control + Shift + I
```
function ConnectButton(){
  console.log("Connect pushed");
  document.querySelector("#top-toolbar > colab-connectbutton").shadowRoot.querySelector("#connect").click()
}
setInterval(ConnectButton,60000);
```