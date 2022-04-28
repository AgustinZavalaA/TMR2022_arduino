from vectores_ult import calculate_vector
import pytest


def test_vectors():
    angle_vector = [90, 225, 180, 135, 45, 0, 315]

    distance_vector = [5, 5, 5, 5, 5, 5, 5]
    distance_vector_2 = [1, 5, 5, 5, 5, 5, 5]
    distance_vector_3 = [0, 5, 0, 5, 5, 5, 5]
    distance_vector_4 = [0, 5, 5, 5, 5, 0, 5]

    
                                                          # (0, 5, 90, 5)
    #print(calculate_vector(distance_vector, angle_vector))
    assert (calculate_vector(distance_vector, angle_vector)) == pytest.approx((0, 5, 90, 5))
    #print(calculate_vector(distance_vector_2, angle_vector))
    assert calculate_vector(distance_vector_2, angle_vector) == pytest.approx((0, 1, 90, 1))
    #print(calculate_vector(distance_vector_3, angle_vector))
    assert calculate_vector(distance_vector_3, angle_vector) == pytest.approx((5, 0, 180, 5))
    #print(calculate_vector(distance_vector_4, angle_vector))
    assert calculate_vector(distance_vector_4, angle_vector) == pytest.approx((-5, 0, 0, 5))

    '''
    (-8.881784197001252e-16, 4.999999999999999, 90.00000000000001, 4.999999999999999)
    (-8.881784197001252e-16, 0.9999999999999991, 90.00000000000006, 0.9999999999999991)
    (4.999999999999999, -8.881784197001252e-16, 180.0, 4.999999999999999)
    (-5.000000000000001, -4.440892098500626e-16, 5.088887490341626e-15, 5.000000000000001)
    '''


if __name__ == "__main__":
    test_vectors()
