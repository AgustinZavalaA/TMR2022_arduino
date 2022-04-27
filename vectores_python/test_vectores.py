from vectores_ult import calculate_vector
import pytest


def test_vectors():
    angle_vector = [90, 225, 180, 135, 45, 0, 315]

    distance_vector = [5, 5, 5, 5, 5, 5, 5]
    distance_vector_2 = [0, 5, 5, 5, 5, 5, 5]
    distance_vector_3 = [5, 5, 0, 5, 5, 5, 5]
    distance_vector_4 = [5, 5, 5, 5, 5, 0, 5]

    assert calculate_vector(distance_vector, angle_vector) == pytest.approx((0, 5, 90, 5))
    assert calculate_vector(distance_vector_2, angle_vector) == pytest.approx((0, 0, 0, 0))
    assert calculate_vector(distance_vector_3, angle_vector) == pytest.approx((-5, 0, 180, 5))
    assert calculate_vector(distance_vector_4, angle_vector) == pytest.approx((5, 0, 0, 5))


if __name__ == "__main__":
    test_vectors()
