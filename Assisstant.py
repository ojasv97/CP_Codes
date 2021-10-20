# -*- coding: utf-8 -*-
"""
Created on Wed May 27 07:36:17 2020

@author: ojas
"""

import speech_recognition as sr
import wikipedia
import pyaudio
from gtts import gTTS
import os
import re
import pyautogui
import spacy


def natural_language_processing(txt):
    nlp = spacy.load('en_core_web_sm') #Database and models for english language
##    txt = ('what is today''s date?')
    txt = txt.lower()

    doc = nlp(txt) #Making a spacy_object

    stopwords = spacy.lang.en.stop_words.STOP_WORDS  #loading the list of stopwords

    #Creating filtered tokens -- 1:No stop words  2:Lemmatised  3:Lowercase  4:No punctuation

    filtered_tokens = [str(x) for x in doc if (not x.is_stop and not x.is_punct)]
    txt2 = ' '.join(filtered_tokens)
    print(txt2)
    doc2 = nlp(txt2)
    for ent in doc.ents:
        print(ent.text, ent.start_char, ent.end_char,ent.label_,spacy.explain(ent.label_))
    for ent in doc2.ents:
        print(ent.text, ent.start_char, ent.end_char,ent.label_,spacy.explain(ent.label_))

natural_language_processing()


#Function to record audio.
def record_audio():
    #To list every i/o device
    mic_list = sr.Microphone.list_microphone_names()
    
    r = sr.Recognizer()
    
    with sr.Microphone() as source:
        r.adjust_for_ambient_noise(source)
        print("Say Something")
        audio = r.listen(source)
        try: 
            text = r.recognize_google(audio) 
            print("you said: " + text) 
          
        except sr.UnknownValueError: 
            print("Google Speech Recognition could not understand audio") 
          
        except sr.RequestError as e: 
            print("Could not request results from Google Speech Recognition service; {0}".format(e)) 
         

def response(text):
    print(text)

    #Text->Speech

    speech = gTTS(text = text,lang = 'en',slow=False)
    speech.save('response.mp3')
    os.system('start response.mp3')

def get_querry(text):
    name = ["mario"]
    text = text.lower()
    if name not in text:
        return False
    text.remove("mario")
    return text
    
    




































    
