import random
import math

def calc_ae(y, y_hat):
    """
    Tính sai số tuyệt đối (Absolute Error)
    giữa giá trị thực tế và giá trị dự đoán.

    Tham số:
    y (float hoặc int): Giá trị thực tế (ground truth).
    y_hat (float hoặc int): Giá trị dự đoán.

    Trả về:
    float: Giá trị tuyệt đối của hiệu giữa y và y_hat.
    """
    return abs(y - y_hat)

y = 1
y_hat = 6
assert calc_ae(y, y_hat)==5

def calc_se(y, y_hat):
    """
    Tính sai số bình phương (Squared Error)
    giữa giá trị thực tế và giá trị dự đoán.

    Tham số:
    y (float hoặc int): Giá trị thực tế (ground truth).
    y_hat (float hoặc int): Giá trị dự đoán.

    Trả về:
    float: Bình phương của hiệu giữa y và y_hat.
    """
    return (y-y_hat)**2
y = 4
y_hat = 2
assert calc_se(y, y_hat) == 4

def cal_activation_function():
    num_samples = input('Input number of samples (integer number) which are generated: ')
    if not num_samples.isnumeric():#Hàm isnumeric() trong Python trả về true nếu một chuỗi dạng Unicode chỉ chứa các ký tự số,
    #nếu không là false.
        print("number of samples must be an integer number")
        return # exit()
    loss_name = input('Input loss name: ')

    # giả sử người dùng luôn nhập đúng MAE, MSE hoặc RMSE
    final_loss = 0
    num_samples = int(num_samples)
    for i in range(num_samples):
        pred_sample = random.uniform(0,10)
        target_sample = random.uniform(0,10)

        if loss_name == 'MAE':
            loss = calc_ae(pred_sample, target_sample)
        elif loss_name == 'MSE' or loss_name == 'RMSE':
            loss = calc_se(pred_sample, target_sample)
        # hoặc trả về thông báo loss không có
        final_loss += loss
        print(f'loss_name: {loss_name}, sample: {i}: pred: {round(pred_sample,2)} target: {round(target_sample,2)} loss: {round(loss,2)}')

    final_loss /= num_samples
    if loss_name == 'RMSE':
        final_loss = math.sqrt(final_loss)
    print(f'final {loss_name}: {final_loss}')
    return final_loss

if __name__=="__main__":
    _ = cal_activation_function()