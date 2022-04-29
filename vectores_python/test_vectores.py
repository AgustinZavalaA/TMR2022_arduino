from vectores_ult import calculate_vector
import pytest


def test_vectors():
    angle_vector = [90, 225, 180, 135, 45, 0, 315]

    distance_vector = [5, 5, 5, 5, 5, 5, 5]
    distance_vector_2 = [1, 5, 5, 5, 5, 5, 5]
    distance_vector_3 = [0, 5, 0, 5, 5, 5, 5]
    distance_vector_4 = [0, 5, 5, 5, 5, 0, 5]

    distance_vector_5 = [3, 5, 5, 5, 5, 9, 5]
    distance_vector_6 = [4, 5, 8, 5, 5, 5, 5]
    distance_vector_7 = [0, 9, 8, 5, 5, 5, 5]
    distance_vector_8 = [0, 5, 5, 8, 5, 5, 9]

    assert (calculate_vector(distance_vector, angle_vector)) == pytest.approx((0, 5, 90, 5))
    assert calculate_vector(distance_vector_2, angle_vector) == pytest.approx((0, 1, 90, 1))
    assert calculate_vector(distance_vector_3, angle_vector) == pytest.approx((5, 0, 180, 5))
    assert calculate_vector(distance_vector_4, angle_vector) == pytest.approx((-5, 0, 0, 5))

    assert calculate_vector(distance_vector_5, angle_vector) == pytest.approx((4, 3, 36.8, 5), 0.01)
    assert calculate_vector(distance_vector_6, angle_vector) == pytest.approx((-3, 4, 126.87, 5), 0.01)
    assert calculate_vector(distance_vector_7, angle_vector) == pytest.approx((-5.82, -2.82, 205.886, 6.47), 0.01)
    assert calculate_vector(distance_vector_8, angle_vector) == pytest.approx((0.70711, -0.70711, -45 + 360, 1), 0.01)


if __name__ == "__main__":
    test_vectors()
