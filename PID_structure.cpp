#define n 5
struct PID
{
  float kP = 20.0;
  float kI = 0.0;
  float kD = 2.0;

  float arr_error[n];
  int index = 0;
  float sum_err = 0;
  float value = 0;
  void update(float error)
  {
    index++;
    index = index < n ? index : 0;
    sum_err -= arr_error[index];
    arr_error[index] = error;
    sum_err += arr_error[index];
    value = kP * arr_error[index] + kI * sum_err - kD * (arr_error[index] - arr_error[index - 1 > 0 ? index - 1 : n - 1]);

    if (false)
    {
      Serial.println();
      Serial.print("P= ");
      Serial.println(kP * arr_error[index]);
      Serial.print("I= ");
      Serial.println(kI * sum_err);
      Serial.print("D= ");
      Serial.println(kD * (arr_error[index] - arr_error[index - 1 > 0 ? index - 1 : n - 1]));
      Serial.println();
    }
  }
};