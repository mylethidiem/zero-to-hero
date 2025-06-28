import math

def calc_f1_score(tp, fp, fn):
    """
    Tính điểm F1 Score từ các giá trị:
    - tp: Số lượng true positives
    - fp: Số lượng false positives
    - fn: Số lượng false negatives

    Công thức:
        precision = tp / (tp + fp)
        recall = tp / (tp + fn)
        f1_score = 2 * (precision * recall) / (precision + recall)

    Trả về:
        f1_score: Điểm F1 Score dưới dạng float
    """
    precision = tp / (tp + fp)
    recall = tp / (tp + fn)
    f1_score = 2 * (precision * recall) / (precision + recall)
    return f1_score

assert round(calc_f1_score(tp=2, fp=3, fn=5), 2) == 0.33

def evaluate_f1_components(tp, fp, fn):
    """
    Tính điểm F1 Score từ các giá trị:
    - tp: Số lượng true positives
    - fp: Số lượng false positives
    - fn: Số lượng false negatives

    Công thức:
        precision = tp / (tp + fp)
        recall = tp / (tp + fn)
        f1_score = 2 * (precision * recall) / (precision + recall)

    Trả về:
        f1_score: Điểm F1 Score dưới dạng float
    """

    # Kiểm tra kiểu dữ liệu
    if not isinstance(tp, int):
        print('tp must be int')
        return None

    if not isinstance(fp, int):
        print('fp must be int')
        return None

    if not isinstance(fn, int):
        print('fn must be int')
        return None

    # Kiểm tra giá trị không âm
    if tp < 0 or fp < 0 or fn < 0:
        print('tp, fp, and fn must be non-negative integers')
        return None

    # Tính precision và recall với xử lý chia cho 0
    precision = tp / (tp + fp) if (tp + fp) > 0 else 0.0
    recall = tp / (tp + fn) if (tp + fn) > 0 else 0.0

    # Tính F1 Score
    f1_score = 2*(precision*recall)/(
        precision+recall) if (precision+recall) > 0 else 0.0

    return precision, recall, f1_score

if __name__=="__main__":
    f1_score = round(calc_f1_score(tp=2, fp=3, fn=5), 2)
    print(f1_score)
    precision, recall, f1_score = evaluate_f1_components(tp=2, fp=3, fn=5)
    print(precision, recall, f1_score)