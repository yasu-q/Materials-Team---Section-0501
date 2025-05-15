double average(double values[], int count) {
  double sum = 0;
  for (int i = 0; i < count; i++) {
    sum += values[i];
  }
  return sum / (double)count;
}

