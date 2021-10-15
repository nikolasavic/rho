if [ "$(uname -s)" == "Darwin" ]; then
  gindent src/* test/*
  rm src/*~ test/*~
elif [ "$(uname -s)" == "Linux" ]; then
  indent src/* test/*
  rm src/*~ test/*~
fi
