from vosk import Model, KaldiRecognizer  # vosk - библиотека для распознания речи
import pyaudio  # библиотека для записи голоса
import json

model = Model('small_model')
rec = KaldiRecognizer(model, 16000)
p = pyaudio.PyAudio()
stream = p.open(format=pyaudio.paInt16, channels=1, rate=16000, input=True, frames_per_buffer=8000)
stream.start_stream()


def listen():
    while True:
        data = stream.read(4000, exception_on_overflow=False)
        if (rec.AcceptWaveform(data)) and len(data) > 0:
            answer = json.loads(rec.Result())
            if answer['text']:
                yield answer['text']


print("say some words and say stop or say stop and write some words")

for text in listen():
    if text != "":
        quit()
    with open("log_pass.txt", "a", encoding="utf-8") as data:
        print(text)
        data.write(text + "\n")
