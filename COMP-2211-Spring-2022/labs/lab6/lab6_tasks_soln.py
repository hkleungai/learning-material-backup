import pandas as pd
import numpy as np
import re
import keras

from numpy import array
from keras.preprocessing.text import one_hot
from keras.preprocessing.sequence import pad_sequences
from keras.models import Sequential
from keras.layers.core import Activation, Dropout, Dense
from tensorflow.keras import regularizers
from keras.layers import Flatten
from keras.layers.embeddings import Embedding
from sklearn.model_selection import train_test_split
from keras.preprocessing.text import Tokenizer
from keras.initializers import HeNormal


def preprocessing(sentence):
    # remove html tags
    tag = re.compile(r'<[^>]+>')
    sentence = tag.sub('', sentence)
    # remove punctuations and numbers
    sentence = re.sub('[^a-zA-Z]', ' ', sentence)
    # remove single char
    sentence = re.sub(r"\s+[a-zA-Z]\s+", ' ', sentence)
    # remove multiple spaces
    sentence = re.sub(r'\s+', ' ', sentence)
    return sentence


def get_X_y(df):
  X = [preprocessing(review) for review in df['review']]
  y = np.asarray([1 if i=='positive' else 0 for i in df["sentiment"]])
  return X,y


def readglovefile(filepath):
  import gzip
  with gzip.open(filepath,'r') as f:
    content=f.readlines()
  return [i.decode('utf8') for i in content]


def formatEmbDict(filepath):
  wordDict = {}
  for string in readglovefile(filepath):
    listinfo = string.split()
    wordDict[listinfo[0]] = np.asarray(listinfo[1:], dtype='float32')
  return wordDict


def myModel(vocab_size, embedding_matrix, maxlen):
  model = Sequential()
  embedding_layer = Embedding(vocab_size, 100, weights=[embedding_matrix], input_length=maxlen , trainable=False)
  model.add(embedding_layer)
  model.add(Dropout(0.2))
  model.add(Dense(
      units=200,
      kernel_initializer=HeNormal(),
      kernel_regularizer=regularizers.l2(0.001)
  ))
  model.add(Activation("relu"))
  model.add(Dropout(0.2))
  model.add(Dense(
      units=50,
      kernel_initializer=HeNormal(),
      kernel_regularizer=regularizers.l2(0.001)
  ))
  model.add(Activation("relu"))
  model.add(Flatten())
  model.add(Dense(1, activation='sigmoid'))
  return model