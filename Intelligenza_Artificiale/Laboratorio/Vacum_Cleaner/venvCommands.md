## Base Venv

mkdir ialabs
cd ialabs

*create venv inside the folder*
python -m venv ialabs1

**Windows:**
ialabs1\Scripts\activate

**Linux/Mac:**
source ialabs1/bin/activate



## Install UV

https://docs.astral.sh/uv/getting-started/installation/

## Venv with uv

*initiate uv in a folder*
uv init

*add packages to the project*
uv add numpy ipykernel Pillow

*launch python through uv*

uv run python
