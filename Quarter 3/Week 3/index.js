import { useState } from "react";
import Head from "next/head";
import styles from "../styles/Home.module.css";
import {
    AlertIcon,
    Button,
    Center,
    Flex,
    Grid,
    GridItem,
    Text,
} from "@chakra-ui/react";
import {
    InputGroup,
    InputLeftAddon,
    FormControl,
    FormLabel,
} from "@chakra-ui/react";
import {
    NumberInput,
    NumberInputField,
    NumberInputStepper,
    NumberIncrementStepper,
    NumberDecrementStepper,
    Slider,
    SliderTrack,
    SliderFilledTrack,
    SliderThumb,
    Alert,
    Box,
} from "@chakra-ui/react";

import "katex/dist/katex.min.css";
import Latex from "react-latex-next";

export default function Home() {
    const [a, setA] = useState(0);
    const [b, setB] = useState(0);
    const [c, setC] = useState(0);
    const [error, setError] = useState("");
    const [precision, setPrecision] = useState(3);
    const [answer, setAnswer] = useState("");

    const formatNumber = (num) => {
        return Number(Number(num).toFixed(precision)).toString();
    };

    const handleSubmit = () => {
        setError("");
        setAnswer("");

        if (!(a && b && c)) {
            return setError("Please enter in all your numbers");
        }

        if (isNaN(a) || isNaN(b) || isNaN(c)) {
            return setError(
                "Please make sure your numbers are entered in correctly."
            );
        }

        const det = calculateDeterminant();
        if (det > 0) {
            setAnswer(
                `$$=\\frac{${formatNumber(-b)} \\pm \\sqrt{(${formatNumber(
                    b
                )})^2-4(${formatNumber(a)})(${formatNumber(
                    c
                )})}}{2(${formatNumber(a)})}$$
                 $$=\\frac{${-b} \\pm ${formatNumber(
                    Math.sqrt(b * b - 4 * a * c)
                )}}{${formatNumber(2 * a)}}$$
                 $$x_1 = ${formatNumber(
                     (-b + Math.sqrt(b * b - 4 * a * c)) / (2 * a)
                 )}, x_2 =${formatNumber(
                    (-b - Math.sqrt(b * b - 4 * a * c)) / (2 * a)
                )}$$`
            );
        } else if (det == 0) {
            setAnswer(
                `$$=\\frac{${formatNumber(-b)}}{2(${formatNumber(a)})}$$
                 $$=\\frac{${-b}}{${formatNumber(2 * a)}}$$
                 $$x = ${formatNumber((-b / 2) * a)}$$`
            );
        } else {
            setAnswer(
                "There are no real solutions because the determinant is negative"
            );
        }
    };

    const calculateDeterminant = () => {
        // console.log(b * b - 4 * a * c);
        return b * b - 4 * a * c;
    };

    return (
        <Center>
            <Grid
                w={["100%", "85%", "70%", "30%"]}
                autoRows
                bg="primary"
                m={1}
                gap={1}
            >
                <Box w="100%" borderWidth={["0px", "2px"]} borderRadius='lg' shadow='md' m={[0, 0, 5]} pt={10} pb={5} px={[3, 4, 10]}>
                    <Center>
                        <GridItem rowSpan={1}>
                            <Text fontSize="4xl" color="red.400">
                                <b>Simple Quadform Calculator</b>
                            </Text>
                        </GridItem>
                    </Center>
                    <GridItem rowSpan={1} margin={1}>
                        <Latex>
                            {"$$ax^2+bx+c$$$$\\frac{-b \\pm \\sqrt{b^2-4ac}}{2a}$$"}
                        </Latex>
                    </GridItem>
                    <GridItem>
                        <Center>
                            <Text fontSize="2xl" color='red.400'><b>Set precision</b></Text>
                        </Center>
                        <NumberInput
                            maxW="50px"
                            mr="2rem"
                            value={precision}
                            onChange={(e) => setPrecision(e)}
                        >
                            <NumberInputField />
                        </NumberInput>
                        <Slider
                            margin={2}
                            flex
                            value={precision}
                            onChange={(e) => setPrecision(e)}
                            defaultValue={3}
                            min={0}
                            max={10}
                            colorScheme="red"
                        >
                            <SliderTrack>
                                <SliderFilledTrack />
                            </SliderTrack>
                            <SliderThumb bg='red.500' borderWidth='1px' fontSize="sm" boxSize="32px" border />
                        </Slider>
                    </GridItem>
                    <Center>
                        <GridItem colSpan={1} rowSpan={1}>
                            <FormControl id="amount">
                                <InputGroup m={2}>
                                    <FormLabel>a</FormLabel>
                                    <NumberInput onChange={(e) => setA(e)}>
                                        <NumberInputField />
                                    </NumberInput>
                                </InputGroup>
                                <InputGroup m={2}>
                                    <FormLabel>b</FormLabel>
                                    <NumberInput onChange={(e) => setB(e)}>
                                        <NumberInputField />
                                    </NumberInput>
                                </InputGroup>
                                <InputGroup m={2}>
                                    <FormLabel>c</FormLabel>
                                    <NumberInput onChange={(e) => setC(e)}>
                                        <NumberInputField />
                                    </NumberInput>
                                </InputGroup>
                                <Center>
                                    <Button
                                        mt={2}
                                        colorScheme="red"
                                        type="submit"
                                        onClick={handleSubmit}
                                    >
                                        Calculate
                                    </Button>
                                </Center>
                            </FormControl>
                        </GridItem>
                    </Center>
                    {error && (
                        <Center>
                            <GridItem rowSpan={1} m={5}>
                                <Alert status="error" rounded={"md"}>
                                    <AlertIcon />
                                    Please check that you have entered in the
                                    numbers correctly
                                </Alert>
                            </GridItem>
                        </Center>
                    )}
                    <Center>
                        <GridItem colSpan={1} rowSpan={1} margin={3}>
                            {answer && <Latex>{answer}</Latex>}
                        </GridItem>
                    </Center>
                </Box>
            </Grid>
        </Center>
    );
}
